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

int check_n(char c){
    if(c== 'v')
        return 7;
    else if(c >=97 && c <= 122)
        return 3;
    else
        return 8;
}

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

int check_alpha(char c){
    if( c == 'g')
        return 1;
    else if ((c >=97 && c <= 122) && c != 'g')
        return 0;
    else
        return 8;
}

int check_phi(char c){
    if( c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

int q8_k37(char* word, int start, int end){
    while( start < end ){
        printf("Char '%c', started in state q8 and went to q8 (trap state) \n", word[start]);
        start++;
    }
    return 8;
}

int q7_k37(char *word, int start, int end){
    if (check_phi(word[start])){
        return 7;
    }
    else return 0;
}

int q6_k37(char *word, int start, int end){
    if( check_n(word[start]) == 7){
        return 7;
    }
    else if (check_phi(word[start]) == 3)
        return 3;
    else if (word[start] == period)
        return 4;
    else 
        return 8;
}

int q5_k37(char *word, int start, int end){
    if( check_delta(word[start]) == 1){
        return 7;
    }
    else if (check_delta(word[start]) == 2)
        return 6;
    else if (check_delta(word[start]) == 3)
        return 4;
    else if(check_delta(word[start]) == 0)
        return 3;
    else 
        return 8;
}

int q4_k37(char *word, int start, int end){
    if( check_alpha(word[start]) == 1){
        return 5;
    }
    else if (check_phi(word[start]) == 0)
        return 3;
    else 
        return 8;
}

int q3_k37(char *word, int start, int end){
    if(check_phi(word[start])){
        return 3;
    }
    else if (word[start] == period)
        return 4;
    else 
        return 8;
}

//checks if contuines onto q3 with phi or goes to trap state with anything else
int q2_k37(char *word, int start, int end){
    if(check_phi(word[start])){
        return 3;
    }
    if (word[start] == period)
        return 4;
    else
        return 8;
}

//checks if contuines onto q2 with @ or goes to q1 with phi or goes to q0 with period or not legal input thus trap state
int q1_k37(char *word, int start, int end){
    if(check_phi(word[start]))
        return 1;
    else if (word[start] == period)
        return 0;
    else if (word[start] == at )
        return 2;
    else
        return 8;
}

//checks if contuines onto q1 or goes to trap state
int q0_k37(char *word, int start, int end){
    printf("q0 \n");
    if(check_phi(word[start])){
        return 1;
    }
    else{
        return 8;
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
    for (int str=1; str<=num; str++){
        printf("Enter string %d out of %d \n", str, num);
        scanf("%s", buff);
        printf("String %d: %s\n", str,buff);
        int length = strlen(buff);
        int start = 0;
        printf("length: %d\n", length);
        /* 
            states goes as followed by number ie 0 = q0
            the line for prev intliazes and checks if it will forever be in trap or go onto q1
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
                    prev = q8_k37(buff, start, length);
                    break;
                default:
                    break;
            }
            start++;
        }
        if(prev == 8){
                printf("String %s is not a legal email address\n", buff);
            }
            else if (start == length && prev == 7){
                printf("String %s is a legal email address\n", buff);
    }
    return 0;
}}