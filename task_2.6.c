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

/*--------------------------------------*/

TrLink treeDel(TrLink tree, unsigned int key){
    if (tree == NULL) {
        return tree;
    }
    
    if (tree->elem == key) {
        if ((tree->left) == NULL && (tree->right) == NULL) { /* the node has no descendants */
            free(tree);
            return NULL;
        } else if ((tree->left) == NULL) { /* the node has only right descendant */
            TrLink tmp = tree;
            tree = tree->right;
            free(tmp);
            return tree;
        } else if ((tree->right) == NULL) { /* the node has only left descendant */
            TrLink tmp = tree;
            tree = tree->left;
            free(tmp);
            return tree;
        } else { /* the node has both descendants */
            TrLink ptr = tree->left;
            if (ptr->right == NULL) { /* left descendant of node is max */
                tree->elem = ptr->elem;
                tree->left = ptr->left;
                free(ptr);
                return tree;
            } else { /* diving to the branch of left descendant to search max */
                TrLink prev = ptr;
                while (ptr->right != NULL) {
                    prev = ptr;
                    ptr = ptr->right;
                }
                if ((ptr->left) == NULL) { /* max subnode has no left descendant */
                    tree->elem = ptr->elem;
                    free(ptr);
                    prev->right = NULL;
                    return tree;
                } else { /* max subnode hasleft descendant */
                    tree->elem = ptr->elem;
                    prev->right = ptr->left;
                    free(ptr);
                    return tree;
                }
            }
        }
    }
    
    if (tree->elem > key) {
        tree->left = treeDel(tree->left, key);
    } else {
        tree->right = treeDel(tree->right, key);
    }
    return tree;
}

/*--------------------------------------*/

void treeScan(TrLink tree, unsigned int key) {
//    if (tree == NULL) {
//        return;
//    }
    
    while (tree != NULL) {
        if (tree->elem == key) {
            printf("%u yes", key);
            putchar('\n');
            return;
        } else if (tree->elem > key) {
            tree = tree->left;
        } else if (tree->elem < key) {
            tree = tree->right;
        }
    }
    printf("%u no", key);
    putchar('\n');
    return;
}

/*--------------------------------------*/


void doTreePrint(TrLink tree, bool printEOL) {
    if (tree == NULL) {
        return;
    }
    
    if (printEOL) {
        printf("[");
    }

    doTreePrint(tree->left, false);
    printf(" %u ", tree->elem);
    doTreePrint(tree->right, false);
    
    if (printEOL) {
        printf("]\n");
    }
}

void treePrint(TrLink tree) {
    if (tree == NULL) {
        printf("[ ]\n");
    }
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
            } else if (op == delete) {
                curtree = treeDel(curtree, collectNum);
            } else if (op == query) {
                treeScan(curtree, collectNum);
            }

            op = add;
            collectNum = 0;
            numLen = 0;
            
            if (chr == '\n') {
                treePrint(curtree);
            } 
            break;
        }
    }
    return 0;
}