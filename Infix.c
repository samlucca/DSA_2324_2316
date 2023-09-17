#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#include "INFIXPOSTFIX.h"

int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

int precedence(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    if(c=='*'||c=='/'){
        return 2;
    }
    return 0;
}

void infixToPostfix(char Infix[],char postfix[]){
    Stack stack;
    init(&stack);
    int i,j=0;

    for(i=0;Infix[i] != '\0';i++){
        if(isdigit(Infix[i])){
            //add to the postfix expression if its a digit
            postfix[j++]=Infix[i];
        }
        else if(Infix[i]=='('){
            push(&stack,Infix[i]);
        }
        else if(Infix[i]==')'){
            while(!is_empty(&stack) && peek(&stack) != '('){
                postfix[j++]=pop(&stack);
            }
            if (!is_empty(&stack) && peek(&stack) == '(') {
                pop(&stack); // Discard '('
            } else {
                printf("Invalid expression: Mismatched parentheses\n");
                return;
            }
        }
        else if(isOperator(Infix[i])){
            while(!is_empty(&stack) && precedence(peek(&stack))>=precedence(Infix[i])){
                postfix[j++]=pop(&stack);
            }
            push(&stack,Infix[i]);
        }
        
    }

//pop remaining operators from the stack
while(!is_empty(&stack)){
    postfix[j++]=pop(&stack);
}
postfix[j] = '\0';
}
