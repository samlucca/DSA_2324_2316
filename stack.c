#include "stack.h"
//push an item onto a stack
void push (Stack* stack,int item){
    if (!is_full(stack)){
        stack->top++;
        stack->data[stack->top]=item;
    }else{
        //optional
    }
}
//pop an item into a stack
int pop (Stack* stack){
    if(!is_empty(stack)){
        int item=stack->data[stack->top];
        stack->top--;
        return item;
    }else{
        //handles stack overflow error here
        return -1;
    }
}
//returns top element
int peek(Stack* stack){
    if(!is_empty(stack)){
	return stack->data[stack->top];
    }
    else{
        return -1;
    }
}
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
