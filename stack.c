#include "stack.h"
//push an item onto a stack
void push (Stack*stack){
    if (!is full(stack)){
        stack->top++;
        stack->data[stack->top]=item;
    }else{
        //optional
    }
}
//pop an item into a stack
void pop (Stack*stack){
    if(!is empty(stack)){
        int item=stack->data[stack->top];
        stack->top--;
    }else{
        //handles stack overflow error here
        return -1;
    }
}