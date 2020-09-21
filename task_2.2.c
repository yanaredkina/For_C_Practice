/* VVO-2course- Redkina Yana - TASK 2.2 */

#include <stdio.h>

int main () {
    double x, a;

    printf("input x and a(i): \n");
    scanf("%lf", &x);

    double polynom = 0, derivative = 0; 

    while (scanf("%lf", &a) == 1) {
        derivative = derivative * x + polynom;
        polynom = a + polynom * x;
    }
    
    printf("Horner's method Polynomial value = %.10g, its derivative = %.10g\n", polynom, derivative);
}