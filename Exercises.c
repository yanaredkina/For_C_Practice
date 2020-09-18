/* VVO-2course- Redkina Yana - Exercises from textbook RUDENKO*/

#include <stdio.h>

/* N 2.29 - Циклически сдвинуть значение целочисленной величины на n позиций влево */
unsigned int mov_nbit(unsigned int x, unsigned char n) {
    unsigned char max_bitsize = sizeof(x) * 8;
    if (n > max_bitsize) {
       printf("incorrect input n, try again");
       return x;
    }
    if (x == 0) {
        return x;
    } else {
        unsigned int high_bits;
        high_bits = x >> (max_bitsize - n);
        x <<= n;
        x = x | high_bits;
    }
    return x;
}

/* 3.21. Подсчитать количество цифр в десятичной записи целого неотрицательного числа n */

unsigned int get_digit(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    unsigned int count = 0;
    while (n) {
        n /= 10;
        count++;
    }
   return count;
}

int main () {
    
    /* N 2.29 */
    printf("new value = %u\n", mov_nbit(3758096384,3));
    
    /* 3.21 */
    printf("number of digits = %u\n", get_digit(2456));
}