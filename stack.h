#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
typedef struct{
	int data[MAX_SIZE];
	int top;
}Stack;

void is_empty(Stack* stack);
int is_full(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack,int item);
int pop(Stack* stack);

#endif
