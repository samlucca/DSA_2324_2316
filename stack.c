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
int peek(Stack* stack){
	return stack->data[stack->top];
}
