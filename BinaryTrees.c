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
    binit(&stack);
    BTREE* current = root;

    while (current != NULL || stack.top != -1) {
        while (current != NULL) {
            printf("%d ", current->data); 
            bpush(&stack, current);
            current = current->left;
        }
        current = bpop(&stack);
        current = current->right;
    }
}


void inOrder(BTREE* root){
    
    Bstack* bstack;
    binit(bstack);

     BTREE* current = root;

    while (current != NULL || !Bis_empty(bstack)) {
        while (current != NULL) {
            bpush(bstack, current);
            current = current->left;
        }
        current = bpop(bstack);
        printf("%d ", current->data); 
        current = current->right;
    }
}


void postOrder(BTREE* root) {
    if (root == NULL)
        return;

    Bstack stack1, stack2;
    binit(&stack1);
    binit(&stack2);

    bpush(&stack1, root);

    while (stack1.top != -1) {
        BTREE* current = bpop(&stack1);
        bpush(&stack2, current);

        if (current->left != NULL)
            bpush(&stack1, current->left);

        if (current->right != NULL)
            bpush(&stack1, current->right);
    }

    while (stack2.top != -1) {
        BTREE* current = bpop(&stack2);
        printf("%d ", current->data); 
    }
}


//stack operations
void binit(Bstack* bstack){
    bstack->top=-1;
}

void bpush(Bstack* bstack, BTREE* node){
    if(!Bis_full(bstack)){
        bstack->top++;
        bstack->nodes[bstack->top]=node;
    }
}

BTREE* bpop(Bstack* bstack){
    if(!Bis_empty(bstack)){  
    return bstack->nodes[bstack->top--];
    }
}

int Bis_empty(Bstack* bstack){
    if(bstack->top==-1)
        return 1;
}

int Bis_full(Bstack* bstack){
    if(bstack->top==MAX-1)
        return 1;
}