/* VVO-2course- Redkina Yana - TASK 2.5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *link; 
typedef struct Node {
    char word[50];
    link next;
} node;
typedef link list;

/*--------------------------------------*/

list lstCreate(char *s) {
    while ((*s == ' ') || (*s == '\t')) {
        s++;
    }
    if (*s == '\0') {
        return NULL;
    }
    
    list lst = (link) malloc (sizeof (node));
    link curlnk = lst;
    
    while (*s != '\0') {
        int i = 0;
        while ((*s != ' ') && (*s != '\t') && (*s != '\0')) {
            curlnk->word[i] = *s;
            i++;
            s++;
            }
             
        while ((*s == ' ') || (*s == '\t')) {
        s++;
        }
        
        if ((*s == '\0') || (*s == '\n')) {
            curlnk->next = NULL;
            break;
        }  
        
        curlnk->next = (list) malloc(sizeof (node));
        curlnk = curlnk->next;        
    }
    return lst;
}
/*--------------------------------------*/

void lstPrint(list lst) {
    while (lst != NULL) {
        printf("%s ", lst->word);
        lst = lst->next;
    }
    putchar('\n');
}

/*--------------------------------------*/

list delSameAsLast(list lst){
    if (lst == NULL) {
        return 0;
    }
    
    if (lst->next == NULL) {
        return lst;
    }
    
    char sample[50];
    list cur = lst;
    
    while (cur->next != NULL) {
        cur = cur->next;
    }
    strcpy(sample, cur->word);
    
    cur = lst;
    list prev = cur; 
    while (cur->next != NULL) {
        if (strcmp (sample, cur->word) == 0) {
            if (cur == lst) {
                lst = lst->next;
                free(cur);
                cur = lst;
                prev = cur;
            } else {    /*(cur != lst)*/
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }

        } else {
            prev = cur;
            cur = cur->next; 
        }

    }
    return lst;
}

/*--------------------------------------*/
/*--------------------------------------*/

int main() {
    printf("Input words: \n");
    
    char buf[1024];
    char chr;
    int i = 0;
    while ((chr = getchar()) != EOF) {
        if (chr != '\n') {
            buf[i++] = chr;
         } else {
             list listOrig = lstCreate(buf);
             putchar('\n');
             printf("Modified List:\n");
             list listModif = delSameAsLast(listOrig);
             lstPrint(listModif);
             i = 0;
         }         
     }     
}