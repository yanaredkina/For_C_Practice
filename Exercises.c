/* VVO-2course- Redkina Yana - Exercises from textbook RUDENKO*/

#include <stdio.h>
#include <math.h>

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
    while (n > 0) {
        n /= 10;
        count++;
    }
   return count;
}

/* 3.31. Дано натуральное число n. Получить наименьшее число вида 2^r, превосходящее n */

unsigned int power_of_two(unsigned int n) {
    unsigned int power_count = 0;
    while (n > 1) {
        n /=  2;
        power_count++;
    }
    return 2 << (power_count); /* pow(2,power_count+1) */
}

int main () {
    
    /* N 2.29 */
    printf("new value = %u\n", mov_nbit(3758096384,3));
    
    /* 3.21 */
    printf("number of digits = %u\n", get_digit(22));
    
    /* 3.31 */
    printf("2r = %u\n", power_of_two(23));

}