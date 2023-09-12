#include <ctype.h>

int size(char * s){
    int count = 0;

    for (char* ptr = s; *ptr != '\0'; ++ptr){
        count++;
    }

    return count;
}

// Two-pointers solution
bool isPalindrome(char * s){
    int l = 0;
    int r = size(s);

    while (l < r){
        while (l < r && !isalnum(s[l])) l++;

        while (l < r && !isalnum(s[r])) r--;

        if (tolower(s[l]) != tolower(s[r])){
            return false;
        }

        l++;
        r--; 
    }

    return true;
}