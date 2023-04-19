
#include <stdio.h>
#include <stdlib.h>

int searchSybmol(char * s1, int len_s1, char * s2, int len_s2) {
    for (int i = 0; i < len_s1; i++) {
        for (int j = 0; j < len_s2; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    char s1[100];
    int len_s1;
    char s2[100];
    int len_s2;

    char ch;

    int i = 0;
    while ((ch = getchar()) != '\n') {
        s1[i] = ch;
        i++;
    }
    len_s1 = i;

    i = 0;
    while ((ch = getchar()) != '\n') {
        s2[i] = ch;
        i++;
    }
    len_s2 = i;

    int indx = searchSybmol(s1, len_s1, s2, len_s2);

    printf("%d", indx);

    return EXIT_SUCCESS;//EXIT_SUCCESS=0;
}


