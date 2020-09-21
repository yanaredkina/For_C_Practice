/* VVO-2course- Redkina Yana - TASK 2.2 */

#include <stdio.h>

int main () {
    
    double x, a;

    printf("input x: \n");
    scanf("%lf", &x);
    
    printf("input a(i): \n");
    
    double res = 0;
    while (scanf("%lf", &a) == 1) {
        res = a + res * x;
    }
    
    printf(" Horner's method Polynomial value is =  %.10g\n", res);
}