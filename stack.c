#include "stack.h"
//push an item onto a stack
void push (stack*stack){
    if (!is full(stack)){
        stack->top++;
        stack->data[stack->top]=item;
    }else{
        //optional
    }
}
//pop an item into a stack
void pop (stack*stack){
    if(!is empty(stack)){
        int item=stack->data[stack->top];
        stack->top--;
    }else{
        //handles stack overflow error here
        return -1;
    }
}