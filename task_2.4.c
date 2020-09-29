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
    
    int count_ip = 1;
    int count_fp = 10;
    int count_dp = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case '.' : state = frac_part; continue;
            case 'E': case 'e': state = degr_part; continue;
            case '-': sign = '-'; continue;
            case '+': sign = '+'; continue;
            case 'F': case 'f': continue;
        }
                
        if (state == int_part) {
            ip = ip * count_ip + (str[i] - '0');
            count_ip *= 10;
        }
        if (state == frac_part) {
            fp = fp + (double)(str[i] - '0') / count_fp ;
            count_fp *= 10;
        }
        if (state == degr_part) {
            dp = dp * count_dp + (str[i] - '0');
            count_dp *= 10;
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