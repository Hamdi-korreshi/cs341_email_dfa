#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Hamdi Korreshi
    Section Number: 006
    Semester: Spring 2024
    Written by: Hamdi Korreshi, hk37@njit.edu
    Instructor: Arashdeep Kaur, ak3257@njit.edu
*/

char period = '.';
char at = '@';

// the N described in the dfa
int check_n(char c){
    if(c== 'v')
        return 7;
    else if(c >=97 && c <= 122)
        return 3;
    else
        return 8;
}

// the delta described in the dfa
int check_delta(char c){
    if( c == 'r')
        return 1;
    else if ( c == 'o')
        return 2;
    else if ((c >=97 && c <= 122))
        return 0;
    else if (c == period)
        return 3;
    else
        return 8;
}

// the alpha described in the dfa
int check_alpha(char c){
    if( c == 'g')
        return 1;
    else if (c >=97 && c <= 122)
        return 0;
    else
        return 8;
}

// the phi described in the dfa
int check_phi(char c){
    if( c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

// trap state: prints out every letter if gotten stuck in trap state to enure no illegal address
int q8_k37(char* word, int start, int end){
    while( start < end ){
        printf("Char '%c', started in state q8 and went to q8 (trap state) \n", word[start]);
        start++;
    }
    return end;
}

// q7 is the final state, however, in this case it is never called if the word is a correct, this state if just more of a check that returns if something like .gov is in the middle
int q7_k37(char *word, int start, int end){
    if (check_phi(word[start])){ // if any letter go back to q3 
        return 3;
    }
    else if(word[start] == period) // if period got back to q4 just incase it keeps going after that
        return 4;
    else 
        return 8; // else return trap
}

// q6 is ensuring that the o in gov is working, and redirects to q3 if anyother letter, if period go to q4
int q6_k37(char *word, int start, int end){
    if( check_n(word[start]) == 7) // checks if recevied v and goes to q7
        return 7;
    else if (check_n(word[start]) == 3) // checks if any other letter other then v and returns to q3
        return 3;
    else if (word[start] == period) // if period go back to q4
        return 4;
    else
        return 8; // otherwise trap state
}

// q5 ensures that you can move onto q7 with r or q6 with o, any other letter results goes back to q3 (represented by delta), period goes back q4 ensuring no double period is possible
int q5_k37(char *word, int start, int end){
    if( check_delta(word[start]) == 1){ // checks if r, if so go to q7
        return 7;
    }
    else if (check_delta(word[start]) == 2) // checks if o, if so go to q6
        return 6;
    else if (check_delta(word[start]) == 3) // checks if period, if so go to q7
        return 4;
    else if(check_delta(word[start]) == 0) // checks if another letter, if so go to q3
        return 3;
    else
        return 8; // otherwise trap
}

// goes back to q3 if any letter other than g (represented by alpha), if a g move onto q5, otherwise trap state useful for avoiding double periods
int q4_k37(char *word, int start, int end){
    if(check_alpha(word[start]) == 1){ // gets a g goes to 4
        return 5;
    }
    else if (check_alpha(word[start]) == 0) // gets a letter in  alpha = {a-z}-g
        return 3;
    else
        return 8; // anything else
}

// takes any extra letters waiting for a period (represented by phi), once a period is provided moves onto q4
int q3_k37(char *word, int start, int end){
    if(check_phi(word[start])){ // gets a word from phi = {a..z}
        return 3;
    }
    else if (word[start] == period) // if a period
        return 4;
    else
        return 8; // other wise trap state
}

//checks if continues onto q3 if a letter is provided otherwise trap state
int q2_k37(char *word, int start, int end){
    if(check_phi(word[start])){ // gets a word from phi = {a..z} and checks if true
        return 3;
    }
    else
        return 8; // otherwise trap state
}

//checks if continues onto q2 with @ or goes to q1 with phi or goes to q0 with period or not legal input thus trap state
int q1_k37(char *word, int start, int end){
    if(check_phi(word[start])) // if it is a letter form phi = {a...z} stay at q1
        return 1;
    else if (word[start] == period) // if a period go back to q0 just to ensure that a letter must follow after that period
        return 0;
    else if (word[start] == at ) // if @ go to q2   
        return 2;
    else
        return 8; // otherwise trap
}

//ensures that a starting letter must be provided at the start of a email or after a period
int q0_k37(char *word, int start, int end){
    if(check_phi(word[start])){ // if a letter in phi = {a..z} go to q1 
        return 1; 
    }
    else{
        return 8; // otherwise trap
    }
}

int main() {
    printf("Project 1 for CS341 \n");
    printf("Section number: 004 \n");
    printf("Semester: Spring 2024 \n");
    printf("Written by: Hamdi Korresi, hk37 \n");
    printf("Project 1 for CS341 \n");
    printf("Enter a number, n >= 0, for strings to process: \n");
    int num;
    scanf("%d\n",&num);
    if( num <= 0){
        printf("Not enough strings\n");
        return 1;
    }
    char buff[100];
    printf("%d strings to be processed\n", num);
    printf("---------------------------------------------------------\n\n");
    for (int str=1; str<=num; str++){
        printf("Enter string %d out of %d \n", str, num);
        scanf("%s", buff);
        printf("String %d: %s\n", str,buff);
        int length = strlen(buff);
        int start = 0;
        printf("length: %d\n", length);
        /*
            states goes as followed by number ie 0 = q0
            the line for prev initializes and checks if it will forever be in trap or go onto q1
        */
        int prev = q0_k37(buff, start, length);
        printf("Char '%c', started in state q0 and went to q%d\n", buff[start], prev);
        start++;
        while (start < length) {
            switch (prev)
            {
                case 0:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q0_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;\
                case 1:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q1_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 2:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q2_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 3:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q3_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 4:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q4_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 5:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q5_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 6:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q6_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 7:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    prev = q7_k37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 8:
                    printf("Char '%c', started in state q%d and went to q8 (trap state) \n", buff[start], prev);
                    prev = q8_k37(buff, start+1, length);
                    break;
                default:
                    start = length;
                    break;
            }
            start++;
        }
        if(prev == 7)
            printf("String %s is a legal email address\n", buff);
        else
            printf("String %s is not a legal email address\n", buff);
        printf("---------------------------------------------------------\n\n");
    }
    return 0;
}