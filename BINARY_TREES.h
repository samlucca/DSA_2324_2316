#ifndef BINARY_TREES
#define BINARY_TREES

#define MAX 50

//strucutre for node in a tree
typedef struct node
{
    int data;
    struct node *left, *right;
}BTREE;

//create tree with x as a root node
BTREE* createTree(int x);

void preOrder(BTREE* root);
void postOrder(BTREE* root);
void inOrder(BTREE* root);


//stack for traversal algorithms
typedef struct Bstack{

    BTREE* nodes[MAX];
    int top;

}Bstack;

void init(Bstack* bstack);
void push(Bstack* bstack, BTREE* node);
BTREE* pop(Bstack* bstack);
int is_empty(Bstack* bstack);
int is_full(Bstack* bstack);

#endif