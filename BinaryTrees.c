#include <stdio.h>
#include <stdlib.h>
#include "BINARY_TREES.h"


BTREE* createTree(int x){

    if(x != -1){

        BTREE* node = (BTREE*)malloc(sizeof(BTREE));

        node->data=x;
        node->left=NULL;
        node->right=NULL;

        int info;
        printf("Enter left child of %d (-1 if none)\n",x);
        scanf("%d",&info);
        if(info!=-1){
            node->left = createTree(info);
        }

        printf("Enter right child of %d (-1 if none)\n",x);
        scanf("%d",&info);
        if(info!=-1){
            node->right = createTree(info);
        }
    
    return node;
    }

return NULL;
}


void preOrder(BTREE* root) {
    if (root == NULL)
        return;

    Bstack stack;
    init(&stack);
    BTREE* current = root;

    while (current != NULL || stack.top != -1) {
        while (current != NULL) {
            printf("%d ", current->data); 
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        current = current->right;
    }
}


void inOrder(BTREE* root){
    
    Bstack* bstack;
    init(bstack);

     BTREE* current = root;

    while (current != NULL || !is_empty(bstack)) {
        while (current != NULL) {
            push(bstack, current);
            current = current->left;
        }
        current = pop(bstack);
        printf("%d ", current->data); 
        current = current->right;
    }
}


void postOrder(BTREE* root) {
    if (root == NULL)
        return;

    Bstack stack1, stack2;
    init(&stack1);
    init(&stack2);

    push(&stack1, root);

    while (stack1.top != -1) {
        BTREE* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
            push(&stack1, current->left);

        if (current->right != NULL)
            push(&stack1, current->right);
    }

    while (stack2.top != -1) {
        BTREE* current = pop(&stack2);
        printf("%d ", current->data); 
    }
}


//stack operations
void init(Bstack* bstack){
    bstack->top=-1;
}

void push(Bstack* bstack, BTREE* node){
    if(!is_full(bstack)){
        bstack->top++;
        bstack->nodes[bstack->top]=node;
    }
}

BTREE* pop(Bstack* bstack){
    if(!is_empty(bstack)){  
    return bstack->nodes[bstack->top--];
    }
}

int is_empty(Bstack* bstack){
    if(bstack->top==-1)
        return 1;
}

int is_full(Bstack* bstack){
    if(bstack->top==MAX-1)
        return 1;
}