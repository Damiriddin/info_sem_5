#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STACK_SIZE 100
#define NUMBER '0'
static double stack[STACK_SIZE];
static int top = -1;
#define MAXOP 100

void push(double n) {
    if (top + 1 < STACK_SIZE) {
        stack[++top] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}

double pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("error: stack is empty\n");
        exit(222);
    }
}


int getop(char* s) {
    int i = 0;
    char c;
    while ((c = getchar()) == ' ' || c == '\t');

    if (isdigit(c)) {
        s[i++] = c;
        while (i < MAXOP && isdigit(c = getchar()) || c == '.') {
            s[i++] = c;
        }
        s[i] = '\0';
        return NUMBER;
    } else if (c == '\n' || c == EOF) {
        return '\n';
    }
    s[i++] = c;

    while (i < MAXOP && (c = getchar()) != ' ' && c != '\n' && c != EOF && c != '\t') {
        s[i++] = c;
    }
    if (c == '\n' || c == EOF) {
        rewind(stdin);
    }
    s[i] = '\0';

    if (!strcmp("+", s)) {
        return '+';
    } else if (!strcmp("-", s)) {
        return '-';
    } else if (!strcmp("*", s)) {
        return '*';
    } else if (!strcmp("/", s)) {
        return '/';
    } else if (!strcmp("%", s)) {
        return '%';
    } else if (!strcmp("sin", s)) {
        return 's';
    } else if (!strcmp("cos", s)) {
        return 'c';
    } else if (!strcmp("^", s)) {
        return '^';
    }

    return 0;
}

