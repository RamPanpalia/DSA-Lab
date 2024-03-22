#include "count.h"

int count(char *string) {
    int cnt = 0;
    char* vowels = "aeiou";
    for (int i = 0; i < strlen(string); i++) {
        if (strchr(vowels, tolower(string[i])) == NULL){
            cnt++;
        }
    }
    return cnt;
}