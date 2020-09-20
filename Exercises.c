/* VVO-2course- Redkina Yana - Exercises from textbook RUDENKO */

#include <stdio.h>
#include <math.h>
#include <string.h>

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

/* 5.33. Программа. Описать функцию f(s, n, x), определяющую, какой символ реже других (но не нуль раз) встречается в строке s и сколько раз он в нее входит. 
         Если таких символов несколько, то взять первый из них по алфавиту. С помощью этой функции провести анализ строки str */

void get_raresymbol(char s[], unsigned int *n, unsigned int *x) {
    int i;
    unsigned int symb[255];
    
    for (i = 0; i <= 255; i++) {
        symb[i] = 0;
    }
    
    i = 0;
    while (s[i] != '\0') {
        symb[s[i]]++;
        i++;
    }
    
    unsigned int min, indx;
    min = strlen(s);
    
    for (i = 0; i <= 255; i++) {
        if ( (symb[i] != 0) && (symb[i] < min)) {
            min = symb[i];
            indx = i;
        }
    }
   
    *x = indx;
    *n = min;
    
 }   

/* ----------------------------------- MAIN ------------------------------ */
 
int main () {
    
    /* 2.29 */
    printf("2.29: new value = %u\n", mov_nbit(3758096384,3));
    /* Results: new value = 7 */
    
    /* 3.21 */
    printf("3.21: number of digits = %u\n", get_digit(22));
    /* Results: number of digits = 2 */
    
    /* 3.31 */
    printf("3.31: n < %u\n", power_of_two(23));
    /* Results: n < 32 */
    
    /* 5.33 */
    char strg[ ] = "sabyyaaabbs";
    unsigned int x, n;
    
    get_raresymbol(strg, &n, &x);
    printf("5.33: strg = %s\n", strg);
    printf("x=%c, n=%u\n", x, n);
    
    /* Results: x=s, n=2*/

/* 5.7. Что напечатает следующая программа? */
    
    char str[ ] = "SSSWILTECH1\1\11W\1WALLMP1";
    
    printf("5.7: ");
        
    int i, c;
     for (i = 2; (c = str [i]) != '\0'; i++) { 
         switch (c) {
         case 'a':
             putchar('i');
             continue;
         case '1':
             break;
         case 1:
             while ((c = str [++i]) != '\1' && c != '\0');
         case 9:
             putchar('S');
         case 'E':
         case 'L':
             continue;
         default:
             putchar(c); 
             continue;
         } 
         putchar(' ');
     }
     putchar('\n'); 
    
    /* Results: SWITCH SWAMP */
    
/* 5.10. Что напечатает следующая программа? */
    
    printf("5.10: \n");
    
     int a[3][3] = {
         { 1, 2, 3 },
         { 4, 5, 6 },
         { 7, 8, 9 }
     };

     int *pa[3] = {a[0], a[1], a[2]};
     int *p = a[0];

     for (i = 0; i < 3; i++) {
         printf(" a[ i ][ 2 – i ]=%d *a[ i ]=%d *(*(a+i)+i)=%d\n", a[i][2 - i], *a[i], *(*(a + i) + i));
     }
     for (i = 0; i < 3; i++) {
         printf("*pa[ i ]=%d p[ i ]=%d \n", *pa[i], p[i]);
     }
     

     /*Results:  a[ i ][ 2 – i ]=3 *a[ i ]=1 *(*(a+i)+i)=1
                 a[ i ][ 2 – i ]=5 *a[ i ]=4 *(*(a+i)+i)=5
                 a[ i ][ 2 – i ]=7 *a[ i ]=7 *(*(a+i)+i)=9
                *pa[ i ]=1 p[ i ]=1 
                *pa[ i ]=4 p[ i ]=2 
                *pa[ i ]=7 p[ i ]=3 */
     
}