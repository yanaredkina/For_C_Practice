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
list listOrig, listModif;


/*--------------------------------------*/

list lstCreate(char *s) {
    link curlnk;
    list lst;
    
    while ((*s == ' ') || (*s == '\t')) {
    s++;
    }
    if (*s == '\0') {
        return NULL;
    }
    
    lst = (link) malloc (sizeof (node));
    curlnk = lst;
    
    while (*s != '\0') {
        int i = 0;
        while ((*s != ' ') && (*s != '\t') && (*s != '\0')) {
            curlnk->word[i] = *s;
            i++;
            s++;
            }
            
        curlnk->word[i] = '\0';
             
        while ((*s == ' ') || (*s == '\t')) {
        s++;
        }
        
        if (*s == '\0') {
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
        if (strcmp (sample, cur->word) == 0) {  /* ??????????????????? */
            printf("yes");
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

int main() {
    printf("Input words: \n");
    
    char str[1024];
    int i = 0;
    while (1) {
        char chr = getchar();
        if (chr == EOF) {
            break;
         }
         str[i++] = chr;
     }
     
    listOrig = lstCreate(str);
    lstPrint(listOrig);
    
    listModif = delSameAsLast(listOrig);
    lstPrint(listModif);
        
}