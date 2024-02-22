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

char phi[26];
char period = '.';
char at = '@';

void init(){
    for (char c = 'a'; c <= 'z'; c++) {
        phi[c - 'a'] = c;
    }
    return;
}

int check_phi(char c){
    if( c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

int q8_hk37(char* word, int start, int end){
    printf("q8 (trap state)\n");
    while( start < end ){
        printf("%c ", word[start]);
        start++;
    }
    return 1;
}

int q2_hk37(char *word, int start, int end){
    if(check_phi(word[start])){
        return q3_hk37(word, start+1, end);
    }
    else 
        return q8_hk37(word, start+1, end);
}

int q1_hk37(char *word, int start, int end){
    while( start < end ){
        if(check_phi(word[start]))
            continue;
        else if (word[start] == period)
            q0_hk37(word,start+1,end);
        else if (word[start] == at )
            q2_hk37(word,start+1,end);
        else
        { 
            q8_hk37(word,start,end);
            return 1;
        }
    }
    return 0;
}

int q0_hk37(char *word, int start, int end){
    printf("q0\n");
    if(check_phi(word[start])){
        q1_hk37(word,start+1,end);
    }
    else{
        q8_hk37(word,start+1,end);
        return 1;
    }
    return 0;
}

int main() {
    init();
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
        printf("String 1: %s\n", buff);
    }
    return 0;
}