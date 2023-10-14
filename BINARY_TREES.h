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

void binit(Bstack* bstack);
void bpush(Bstack* bstack, BTREE* node);
BTREE* bpop(Bstack* bstack);
int Bis_empty(Bstack* bstack);
int Bis_full(Bstack* bstack);

#endif