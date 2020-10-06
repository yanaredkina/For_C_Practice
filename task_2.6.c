/* VVO-2course- Redkina Yana - TASK 2.6 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode *TrLink; 
typedef struct TreeNode {
    unsigned int elem;
    TrLink left;
    TrLink right;
} tnode;

enum parser_state {operation, number};
enum operation {add, delete, query};

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
        tree->left = treeAdd(tree->left, key);
    } else {
        tree->right = treeAdd(tree->right, key);
    }
    return tree;
}


//TrLink treeDel(TrLink tree, unsigned int key);

//void treeScan(TrLink tree, unsigned int key);

/*--------------------------------------*/


void doTreePrint(TrLink tree, bool printEOL) {
    if (tree == NULL) {
        return;
    }

    doTreePrint(tree->left, false);
    printf(" %u ", tree->elem);
    doTreePrint(tree->right, false);
    
    if (printEOL) {
        putchar('\n');
    }
}

void treePrint(TrLink tree) {
    doTreePrint(tree, true);
}

/*--------------------------------------*/

int main() {
    printf("input <operation> & <number>:\n");
    
    enum parser_state state = operation;

    enum operation op = add;
    unsigned int collectNum = 0;
    unsigned int numLen = 0;
    
    TrLink curtree = NULL;

    char chr;
    while ((chr = getchar()) != EOF) {
        switch (chr) {
        case '+' :
            if (state == number) {
                printf("there was an error in input\n");
                break;
            }
            state = number;
            op = add;
            break;
        case '-':
            if (state == number) {
                printf("there was an error in input\n");
                break;
            }
            state = number;
            op = delete;
            break;
        case '?':
            if (state == number) {
                printf("there was an error in input\n");
                break;
            }
            state = number;
            op = query; 
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
            if (state == operation) {
                printf("there was an error in input\n");
                break;
            }
            collectNum = collectNum * 10 + (chr - '0');
            numLen++;
            break;
        case ' ':
        case '\t':
        case '\n':
            if (state == operation) {
                break;
            }
            if (numLen == 0) {
                printf("there was an error in input\n");
                break;
            }
            state = operation;

            if (op == add) {
                curtree = treeAdd(curtree, collectNum);
//            } else if (op == delete) {
//                curtree = treeAdd(curtree, collectNum);
//            } else if (op == query) {
//                treeScan(curtree, collectNum);
            }

            op = add;
            collectNum = 0;
            numLen = 0;
            break;
        }  
    }
    
    treePrint(curtree);
}