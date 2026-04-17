// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

void firstNonRepeating(char *s) {
    int count[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return;
        }
    }

    printf("$\n");
}

int main() {
    char s[100000];
    if (scanf("%s", s) == 1) {
        firstNonRepeating(s);
    }
    return 0;
}