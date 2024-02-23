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

int check_phi(char c){
    if( c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

int q8_hk37(char* word, int start, int end){
    while( start < end ){
        printf("Char '%c', started in state q8 and went to q8 (trap state) \n", word[start]);
        start++;
    }
    return 8;
}


int q3_hk37(char *word, int start, int end){
    if(check_phi(word[start])){
        return 3;
    }
    else 
        return 8;
}

//checks if contuines onto q3 with phi or goes to trap state with anything else
int q2_hk37(char *word, int start, int end){
    if(check_phi(word[start])){
        return 3;
    }
    if (word[start] == period)
        return 4;
    else
        return 8;
}

//checks if contuines onto q2 with @ or goes to q1 with phi or goes to q0 with period or not legal input thus trap state
int q1_hk37(char *word, int start, int end){
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
int q0_hk37(char *word, int start, int end){
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
    scanf("%d",&num);
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
        printf("length: %d", length);
        /* 
            states goes as followed by number ie 0 = q0
            the line for prev intliazes and checks if it will forever be in trap or go onto q1
        */
        int prev = q0_hk37(buff, start, length);
        printf("Char '%c', started in state q0 and went to q%d\n", buff[start], prev);
        start++;
        while (start < length) {
            switch (prev)
            {
                case 0:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    int prev = q0_hk37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;\
                case 1:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    int prev = q1_hk37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 2:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    int prev = q2_hk37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 3:
                    printf("Char '%c', started in state q%d", buff[start], prev);
                    int prev = q3_hk37(buff, start, length);
                    printf(" and went to q%d\n", prev);
                    break;
                case 8:
                    printf("Char '%c', started in state q%d and went to q8 (trap state) \n", buff[start], prev);
                    int prev = q8_hk37(buff, start, length);
                    break;
                default:
                    break;
            }
            start++;
        }
    }
    return 0;
}