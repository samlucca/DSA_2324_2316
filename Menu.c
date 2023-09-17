#include <stdio.h>
#include "utils.h"
#include "stack.h"
#include "INFIXPOSTFIX.h"

int main(){
	int choice;
int num = 0;

while(num==0){
	printf("1. Insertion Sort \n 2. Bubble sort \n 3. Selection sort \n4. Addition \n5.INFIX to POSTFIX & Evaluation \n0.EXIT");
	printf("\nEnter your choice\n");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:printf(" Insertion sort\n..");
				break;
		case 2:printf(" Bubble sort\n");
				break;
		case 3:printf(" Selection sort\n");
				break;
		case 4:printf(" Addition of 5 and 9 = %d\n",add(5,9));
				break;
		case 5:printf("Postfix Evaluation\n Enter the Infix expression:\n");
				char infix[100],postfix[100];
				scanf("%s", infix);

				infixToPostfix(infix,postfix);
				printf("\nYour expression is:%s",infix);

				printf("\nPostfix expression is:%s",postfix);

				printf("\nAnswer=%d\n",postfixEvaluation(postfix));
				
				break;
		case 0:num=1;
				break;
		
		default:printf("\nEnter valid choice\n");
		}
	}
	printf("Exited the menu.");
	return 0;
	
}
