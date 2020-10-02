/* VVO-2course- Redkina Yana - TASK 2.5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *Link; 
typedef struct Node {
    char word[50];
    Link next;
} node;

/*--------------------------------------*/

Link lstCreate(char *s) {
    while ((*s == ' ') || (*s == '\t')) {
        s++;
    }
    if (*s == '\0') {
        return NULL;
    }
    
    Link list = (Link) malloc(sizeof(node));
    Link curlnk = list;
    
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
        
        curlnk->next = (Link) malloc(sizeof(node));
        curlnk = curlnk->next;        
    }
    return list;
}
/*--------------------------------------*/

void lstPrint(Link list) {
    while (list != NULL) {
        printf("%s ", list->word);
        list = list->next;
    }
    putchar('\n');
}

/*--------------------------------------*/

Link delSameAsLast(Link list){
    if (list == NULL) {
        return 0;
    }
    
    if (list->next == NULL) {
        return list;
    }
    
    Link cur = list;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    
    char sample[50];
    strcpy(sample, cur->word);
    
    cur = list;
    Link prev = cur; 
    while (cur->next != NULL) {
        if (strcmp(sample, cur->word) == 0) {
            if (cur == list) {
                list = list->next;
                free(cur);
                cur = list;
                prev = cur;
            } else {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        } else {
            prev = cur;
            cur = cur->next; 
        }
    }
    return list;
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
             Link listOrig = lstCreate(buf);
             putchar('\n');
             printf("Modified List:\n");
             Link listModif = delSameAsLast(listOrig);
             lstPrint(listModif);
             i = 0;
         }         
     }     
}