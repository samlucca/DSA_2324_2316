#include <stdio.h>
#include "stack.h"
#include "BRACKETS.h"

int bracketMatch(char exp[]){
    int i;
    Stack stack3;
    init(&stack3);
    for(i=0;exp[i];i++){
        char c=exp[i];
        if(c == '(' || c == '{' || c == '['){
            push(&stack3,c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            if(is_empty(&stack3)){
                return 0;
            }
            else if(c==')' && peek(&stack3)=='(' || c=='}' && peek(&stack3)=='{' || c==']' && peek(&stack3)=='['){
                
                pop(&stack3);
                
            }
            else{
                return 0;
            }
        }
    }
    if(is_empty(&stack3)){
        return 1;
    }
    else{
        return 0;
    }
}
