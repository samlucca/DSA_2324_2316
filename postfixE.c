#include <stdio.h>
#include "stack.h"
#include <ctype.h>

int postfixEvaluation(char A[]){

    Stack stack;
    init(&stack);

    int i;

    for(i=0;A[i];i++){

        if(isdigit(A[i])){
            push(&stack,A[i]-'0');
        }

        else if(A[i]==' '){
            continue;
        }
            
        else{
            
            int a=pop(&stack);
            int b=pop(&stack);
            
            switch(A[i]){
                case '+':push(&stack,a+b);
                        break;
                case '-':push(&stack,a-b);
                        break;
                case '*':push(&stack,a*b);
                        break;                        
                case '/':push(&stack,a/b);
                        break;
            }
        }
    }

return pop(&stack);
}
int main(){
    int i;
    char exp[]="2 3 4 * +";
    printf("Expression is:\n");
    for(i=0;exp[i];i++){
        printf("%c",exp[i]);
    }
    printf("\nAnswer=%d",postfixEvaluation(exp));
return 0;
}