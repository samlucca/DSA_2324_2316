#include "stack.h"

//Initialise the stack
void init(Stack* stack){
	stack->top=-1;
}

//check if the stack is empty
int is_empty(Stack* stack){
	return stack->top == -1;
}

//check if the stack is full
int is_full(Stack* stack){
	return stack->top==MAX_SIZE-1;
}
