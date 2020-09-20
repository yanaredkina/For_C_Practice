/* VVO-2course- Redkina Yana - TASK 2.1 */

#include <stdio.h>

double sqrt_newton(double x, double eps) {
    double cur_x = 1.0, nxt_x;
    
    nxt_x = (cur_x + x / cur_x) / 2.0;
    
    while ((cur_x - nxt_x) >= eps || (nxt_x - cur_x) >= eps) {
        cur_x = nxt_x;
        nxt_x = (cur_x + x / cur_x) / 2.0;
    }
    
    return nxt_x;
}
    
    
int main () {
    
    double eps, x;
    
    printf("input epsilon: \n");
    scanf("%lf", &eps);
    
    printf("input x: \n");
    while (scanf("%lf", &x) == 1) {
         printf("sqrt from x is = %.10g\n", sqrt_newton(x, eps));
    }
}