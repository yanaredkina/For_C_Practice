/* VVO-2course- Redkina Yana - TASK 1 */

#include <stdio.h>
#include <limits.h>

int main () {
    
/* 1. Выяснить, сколько байт отведено для хранения данных типа short, int, long, float, double и long double. */
    
    printf("short=%lu, int=%lu, long=%lu, float=%lu, double=%lu, long double=%lu\n", 
        sizeof(short), sizeof(int), sizeof(long), sizeof(float), sizeof(double), sizeof(long double));
    printf("\n");
    /* Results: short=2, int=4, long=8, float=4, double=8, long double=16 */
    
    
/* 2. Выяснить способ представления типа char: signed- или unsigned- вариант. */
    
    printf("CHAR_MINIMUM=%d\n", CHAR_MIN);  
    printf("CHAR_MAXIMUM=%d\n", CHAR_MAX);
    
    char ch = -1;
    if (ch == 255)
        printf("unsigned char\n");
    else 
        printf("signed char\n");
    printf ("\n");
   /* Results: signed char */
        
        
/* 3. Проконтролировать, все ли способы записи констант допустимы:
• целых (обычная форма записи, u/U, l/L, их комбинации, восьмеричная и шестнадцатиричная системы счисления)
• вещественных (обычная форма записи, в экспоненциальном виде, f/F, l/L, e/E )
• символьных и строковых (в частности, происходит ли конкатенация рядом расположенных строковых констант) */
        
    int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15, y16;
    y1 = 1;
    y2 = 2u;
    y3 = 3U;
    y4 = 4l;
    y5 = 5L;
    y6 = 6ul;
    y7 = 7lu;
    y8 = 8UL;
    y9 = 9LU;
    y10 = 10Lu;
    y11 = 11lU;
    y12 = 12uL;
    y13 = 13Ul;
    y14 = 07;
    y15 = 0xB;
    y16 = 0XF;
    
    double x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
    x1 = 11.05;
    x2 = 5.;
    x3 = .12;
    x4 = 33E+2;
    x5 = 7e-6;
    x6 = 8.E+2;
    x7 = 10.2e-3;
    x8 = 2E10;
    x9 = 1.1F;
    x10 = .05f;
    x11 = 5.L;
    x12 = 25e+2l;
    
    char s, t, u, v;
    s = 'S';
    t = '\2';
    u = '\xFF';
    v = '\n';
    
    /* Results: no warning or errors */
    
    char str[] = "This is " "first " "string";
    printf("%s\n", str);
    printf ("\n");
    
    /* Results: This is first string */



/* 4. Выяснить, как упорядочены коды символов '0'-'9', 'a'-'z', 'A'- 'Z', пробел (между собой и относительно друг друга) */    
    
    int i;
    printf("Character code '0'-'9' is:\n");
    for (i = '0'; i <= '9'; i++)
        printf("%d ", i);
    putchar('\n');
    putchar('\n');
    
    printf("Character code 'a'-'z' is:\n");
    for (i = 'a'; i <= 'z'; i++)
        printf("%d ", i);
    putchar('\n');
    putchar('\n');
    
    printf("Character code 'A'-'Z' is:\n");
    for (i = 'A'; i <= 'Z'; i++)
        printf("%d ", i);
    putchar('\n');
    putchar('\n');
    
    /* Results: 
        Character code '0'-'9' is:
        48 49 50 51 52 53 54 55 56 57 

        Character code 'a'-'z' is:
        97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 

        Character code 'A'-'Z' is:
        65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 */



/* 9. Проверьте, действительно ли операции отношения == и != имеют более низкий приоритет, чем все другие операции отношения. */
    
    int a = 1, b = 3, c = 2;
    printf("case one: %s\n", (a == b > c)? " == priority lower than >" : " == priority higher or equal to >");
    
    a = -1;
    printf("case two: %s\n", (c != b <= a)? " == priority lower than >" : " == priority higher or equal to >");
    
    putchar('\n');
    
    /* Results: 
        case one:  == priority lower than >
        case two:  == priority lower than > */
    
/* 12. Определите, каким образом "малое" целое расширяется до int (старшие разряды int заполняются нулями или знаковым разрядом "малого" целого). */
    
    short us = 1, ss = -1;
    int chek_us, chek_ss;
    int bitsize = sizeof(int) * 8 - 1;
        
    chek_us = us;
    chek_ss = ss;
    
    printf("High bits after expansion unsigned short: %d\n", chek_us >> bitsize & 1);
    printf("High bits after expansion signed short: %d\n", chek_ss >> bitsize & 1);
    
    /* Results: 
        High bits after expansion unsigned short: 0
        High bits after expansion signed short: 1 */
    
}