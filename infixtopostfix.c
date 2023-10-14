#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack* sp){
    return sp->arr[sp->top];

}
int isEmpty(struct stack *ptr)
{
    if (ptr->top== -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull (struct stack *ptr){
    if(ptr->top ==ptr->size -1)
{
    return 1;
}else{
    return 0;
}
}
int ptr;
void push(struct stack* ptr,char val){
    if(isFull(ptr)){
        print("Stack Overflow! Cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        prt->arr[ptr->top]=val;
    }
}
char pop(struct stack* ptr, char val){

if (isEmpty(ptr)){
    printf("Stack Underflow!cannot pop from the stack\n");
    return -1;

}else{
    char val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
    }
}
int presedence(char ch){
    if(ch=='*' ||ch=='/')
        return 3;
    else if(ch=='+' ||ch=='-')
        return 2;
    else
       return 0;
}

 intisOperator(char ch){
    if(ch=='+'|| ch=='-'|| ch=='*'|| ch=='/')
    return 1;
    else
    return 0;
}
char * infixToPostfix(char * infix){
struct stack * sp=(struct stack*)malloc(sizeof(struct stack));
sp->size=10;
sp->top= -1;
sp->arr=(char*)malloc(sp->size * sizeof(char));
char * postfix=(char*)malloc((strlrn(infix)+1) * sizeof(char));
int i=0;//track infix
int j=0;//track postfix
while(infix[i]!='\0'){
    if(!isOperator(infix[i])){
        postfix[j]=infix[i];
        j++;
        i++;
    }
    else{
        if(presedence(infix[i])>presedence(stackTop(sp))){
            push(sp,infix[i]);
            i++;

        }
        else{
            postfix[j]=pop(sp);
            j++;

        }
    }
}
    while (!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    
};

int main(){
    char * infix="a-b+t/6";
    printf("postfix is %s",infixToPostfix(infix));
    return 0;

}