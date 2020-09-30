/* VVO-2course- Redkina Yana - TASK 2.4 */

#include <stdio.h>

double str2double(char str[]) {
    enum number {int_part, frac_part, degr_part};
    enum number state = int_part;
    int ip = 0;
    double fp = 0.0;
    int dp = 0;
    double expon = 1;
    char sign = 0;
    
    int count_fp = 10;
    for (int i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case '.' : 
                state = frac_part; 
                break;
            case 'E': 
            case 'e': 
                state = degr_part;
                break;
            case '-': 
                sign = '-';
                break;
            case '+':
                sign = '+';
                break;
            case 'F':
            case 'f': 
                break;
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
                if (state == int_part) {
                    ip = ip * 10 + (str[i] - '0');
                } else if (state == frac_part) {
                    fp = fp + (double)(str[i] - '0') / count_fp ;
                    count_fp *= 10;
                } else if (state == degr_part) {
                    dp = dp * 10 + (str[i] - '0');
                }
                break;
        }
    }
     
    for (int j = 0; j <= (dp - 1); j++) {
        if (sign == '-') {
            expon = expon / 10;
        } else {
            expon = expon * 10;    
        }
    }
    return ((ip + fp) * expon);
}
    

int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        printf("%.10g\n", str2double(str));
    }
}