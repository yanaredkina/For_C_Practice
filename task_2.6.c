/* VVO-2course- Redkina Yana - TASK 2.6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode *TrLink; 
typedef struct TreeNode {
    unsigned int elem;
    TrLink left;
    TrLink right;
} tnode;

/*--------------------------------------*/

TrLink treeAdd(TrLink tree, unsigned int key) {
    if (tree == NULL) {
        tree = (TrLink) malloc(sizeof(tnode));
        tree->elem = key;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    if (tree->elem == key) {
        return tree;
    }
    if (tree->elem > key) {
        treeAdd(tree->left, key);
    } else {
        treeAdd(tree->right, key);
    }   
return tree;
}


//TrLink treeDel(TrLink tree, unsigned int key);

//void treeScan(TrLink tree, unsigned int key);

/*--------------------------------------*/

void treePrint(TrLink tree) {
    if (tree == NULL) {
        return;
    }
    treePrint(tree->left);
    printf("%u ", tree->elem);
    
    treePrint(tree->right);
    printf("%u ", tree->elem);
    
    putchar('\n');
}

/*--------------------------------------*/
/*--------------------------------------*/

int main(){
    printf("Input numbers: \n");
    
    enum input {plus, minus, question, none};
    enum input state = none;
    char chr;
    unsigned int number = 0;
    TrLink curtree = NULL;
    
    while ((chr = getchar()) != EOF) {
        switch (chr) {
        case '+' : 
            state = plus; 
            break;
        case '-': 
            state = minus; 
            break;
        case '?':
            state = question; 
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            number = number * 10 + (chr - '0');
            break;
        case ' ':
        case '\t':
        case '\n':
            if (state == plus) {
                curtree = treeAdd(curtree, number);
                number = 0;
//            } else if (state == minus) {
//                curtree = treeAdd(curtree, number);
//            } else if (state == question) {
//                treeScan(curtree, number);
            }
            break;
        }  
    }
    treePrint(curtree);
}