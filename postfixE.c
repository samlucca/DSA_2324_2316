#include <stdio.h>
#include "stack.h"
#include <ctype.h>
#include "INFIXPOSTFIX.h"

int postfixEvaluation(char A[]){

    Stack stack2;
    init(&stack2);

    int i;

    for(i=0;A[i];i++){

        if(isdigit(A[i])){
            push(&stack2,A[i]-'0');
        }

        else if(A[i]==' '){
            continue;
        }
            
        else{
            
            int a=pop(&stack2);
            int b=pop(&stack2);
            
            switch(A[i]){
                case '+':push(&stack2,a+b);
                        break;
                case '-':push(&stack2,b-a);
                        break;
                case '*':push(&stack2,a*b);
                        break;                        
                case '/':push(&stack2,b/a);
                        break;
            }
        }
    }

return pop(&stack2);
}
