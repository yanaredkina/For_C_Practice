/* VVO-2course- Redkina Yana - TASK 2.3 */

#include <stdio.h>
#include <time.h>

int iter_fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    int f1 = 0, f2 = 1, f_cur; 
    for (int j = 2; j <= i; j++){
        f_cur = f1 + f2;
        f1 = f2;
        f2 = f_cur;
    }
    return  f_cur;
}

int recurs_fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    
    int res;
    res = recurs_fibonacci(i - 2) + recurs_fibonacci(i - 1);
    return res;
}

int main() {
    
    int i;
    
    printf("input number i >= 0: \n");

    while (scanf("%d", &i) != EOF) {
        if (i >= 0) {
            printf("fibonacci number (iteration function) = %d\n", iter_fibonacci(i));
            printf("fibonacci number (recursive function) = %d\n", recurs_fibonacci(i));
        } else {
            printf("incorrect number, try again\n");
        }
    }
    
}