 #include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXOP 100
#define NUMBER '0'

int main() {
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER :
                push (atof (s));
                break;
            case '+' :
                push (pop() + pop());
                break;
            case '*' :
                push (pop() * pop());
                break;
            case '-' :
                op2 = pop();
                push (pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                else {
                    printf("error: zero divisor\n");
                    return 0;
                }
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case '^':
                push(pow(pop(), pop()));
                break;
            case '\n' :
                op2 = pop();
                if (roundf(op2) != op2)
                    printf("%.6f", op2);
                else
                    printf("%d", (int) op2);
                return 0;
            default :
                printf("error: unknown command %s\n", s);
                return 0;
        }
    }
    return 0;
}

