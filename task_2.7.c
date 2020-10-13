/* VVO-2course- Redkina Yana - TASK 2.7 */

#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;
char curlex;
void getlex(void);
int expr(void);
int mul(void);
int expo(void);
int term(void);
void error();

int main() {
    int result;
    setjmp(begin);
    printf("==>");
    getlex();
    result = expr();
    if (curlex != '\n') {
        error();
    }
    printf("\n%d\n", result);
    return 0;
}

void getlex() {
    while ((curlex = getchar()) == ' ') {
    }
}

void error(void) {
    printf("\nERROR!\n");
    while (getchar() != '\n') {
    }
    longjmp(begin, 1);
}

int expr(void) {
    int e = mul();
    while (curlex == '+' || curlex == '-') {
        char op = curlex;
        getlex();
        if (op == '+') {
            e += mul();
        } else {
            e -= mul();
        }
    }
    return e;
}

int mul() {
    int e = expo();
    while (curlex == '*' || curlex == '/') {
        char op = curlex;
        getlex();
        if (op == '*') {
            e *= expo();
        } else {
            e /= expo();
        }
    }
    return e;
}

int expo() {
    int d = term();
    while (curlex == '^') {
        getlex();
        int count = expo();
        int base = d;
        for (int i = 1; i < count; i++) {
            d *= base;
        }       
    }
    return d;
}

int term() {
    int ex;
    switch (curlex) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ex = curlex - '0';
            break;
        case '(':
            getlex();
            ex = expr();
            if (curlex == ')') {
                break;
            }
        default: error();
    }
    getlex();
    return ex;
}