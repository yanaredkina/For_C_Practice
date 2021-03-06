/* VVO-2course- Redkina Yana - TASK 2.3 */

#include <stdio.h>
#include <time.h>

unsigned long int iter_fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    unsigned long int f1 = 0, f2 = 1, f_cur; 
    for (int j = 2; j <= i; j++) {
        f_cur = f1 + f2;
        f1 = f2;
        f2 = f_cur;
    }
    return f_cur;
}

unsigned long int recurs_fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return recurs_fibonacci(i - 2) + recurs_fibonacci(i - 1);
}

int main() {
    printf("input number i >= 0: \n");
    
    int i;
    while (scanf("%d", &i) != EOF) {
        if (i < 0) {
            printf("incorrect number, try again\n");
            continue;
        }
        
        clock_t start = clock();
        unsigned long int value = iter_fibonacci(i);
        clock_t end = clock();
        double duration = ((double) end - start) / CLOCKS_PER_SEC;
        printf("fibonacci number (iteration function) = %lu, took %f seconds to execute\n", value, duration);
        
        start = clock();
        value = recurs_fibonacci(i);
        end = clock();
        duration = ((double) end - start) / CLOCKS_PER_SEC;
        printf("fibonacci number (recursive function) = %lu, took %f seconds to execute\n", value, duration);
    } 
}