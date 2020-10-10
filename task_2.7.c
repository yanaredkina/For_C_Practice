/* VVO-2course- Redkina Yana - TASK 2.7 */

#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;
char curlex;
void getlex(void);
int expr(void);
int add(void);
int sub(void);
int mult(void);
int div(void);
int expon(void);
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
    int e = add();
    while (curlex == '+') {
        getlex(); 
        e += add();
    }
    return e;
}

int add() {
    int a = sub();
    while (curlex == '-') {
        getlex();
        a -= sub();
    }
    return a;
}

int sub() {
    int s = mult();
    while (curlex == '*') {
        getlex();
        s *= mult();
    }
    return s;
}

int mult() {
    int m = div();
    while (curlex == '/') {
        getlex();
        m /= div();
    }
    return m;
}

int div() {
    int d = expon();
    int count = 1;
    while (curlex == '^') {
        getlex();
        count = div();
    }
    for (int i = 1; i < count; i++) {
        d *= d;
    }
    return d;
}

int expon() {
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