/* VVO-2course- Redkina Yana - TASK 2.4 */

#include <stdio.h>

double str2double(char str[]) {
    enum number {int_part, frac_part};
    enum number state = int_part;
    int ip = 0;
    double fp = 0.0;
    
    int count_ip = 1;
    int count_fp = 10;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '.') {
            state = frac_part; continue;
        }
        if (state == int_part) {
            ip = ip * count_ip + (str[i] - '0');
            count_ip *= 10;
        }
        if (state == frac_part) {
            fp = fp + (double)(str[i] - '0') / count_fp ;
            count_fp *= 10;
        }
    }
    return ip + fp;
}
    

int main() {
    char str[] = "31.534";
    printf("%.10f\n", str2double(str));

}