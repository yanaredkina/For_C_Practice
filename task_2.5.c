/* VVO-2course- Redkina Yana - TASK 2.5 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *link; 
typedef struct Node {
    char word[50];
    link next;
} node;
typedef link list;
list listPrt;


//--------------------------------------

list lstCreate (char *s) {
    link curlnk;
    list listPrt;
    
    if (*s == '\0') {
        return NULL;
    }

    listPrt = curlnk = (link) malloc (sizeof (node));
    int i;
    while ( (*s != ' ') && (*s != '\0')){
        curlnk->word[i] = *s;
        i++;
        s++;
        } 
    
    if (*s == ' ') {
        s++;
    };
    
    while ( *s != '\0') {
        curlnk= curlnk->next = (list) malloc( sizeof (node));
        int i;
        while ((*s != ' ') && (*s != '\0')) {
            curlnk->word[i] = *s;
            i++;
            s++;
            } 
    }
    
    curlnk->next = NULL;
    return listPrt; 

}

int main() {
    printf("Input words: \n");
    
    char *str;
    while ((*str = getchar()) != EOF){
        str++;
    }
    
    printf("%s\n",str);
    listPrt = lstCreate(str);
    printf("%s\n", listPrt->word);
}