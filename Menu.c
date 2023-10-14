#include <stdio.h>
#include "utils.h"
#include "stack.h"
#include "INFIXPOSTFIX.h"
#include "BRACKETS.h"
#include "BINARY.h"
#include "BINARY_TREES.h"
#include "DIJKSTRA.h"

int main(){
	
int choice,num=0,x;

while(num==0){

	printf("\nSelect your choice\n");
	printf("1.Addition\n");
	printf("2.Postfix Evaluation\n");
	printf("3.Bracket Matching\n");
	printf("4.Binary Search\n");
	printf("5.Binary trees\n");
	printf("6.Dijkstra's algorithm\n");
	printf("0.Exit\n");
	
	scanf("%d", &choice);
	
	switch (choice){

		case 1:printf(" Addition of 5 and 9 = %d\n",add(5,9));
				break;

		case 2:printf("Postfix Evaluation\n Enter the Infix expression:\n");
				char infix[50],postfix[50];
				scanf("%s", infix);
				infixToPostfix(infix,postfix);
				printf("\nYour expression is:%s",infix);
				printf("\nPostfix expression is:%s",postfix);
				printf("\nAnswer=%d\n",postfixEvaluation(postfix));
				
				break;

		case 3:printf("Enter the expression:\n");
				char exp[50];
				scanf("%s", exp);
				if(bracketMatch(exp)){
					printf("Brackets are correct...\n");
				}
				else{
					printf("Brackets are incorrect...\n");
				}
				break;

		case 4:fileRead();
				break;

		case 5:

				printf("Enter root node\n");
				scanf("%d",&x);

				BTREE *root = createTree(x);

				printf("\npre-order traversal:\n");
				preOrder(root);

				printf("\nin-order traversal:\n");
				inOrder(root);

				printf("\npost-order traversal:\n");
				postOrder(root);
				break; 

		case 6:dijkstra();
				break;

		case 0:num=1;
				break;
		
		default:printf("\nEnter valid choice\n");
		}
	}
	
	printf("Exited the menu.");
	
	return 0;
}
