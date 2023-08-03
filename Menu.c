#include <stdio.h>
#include "utils.h"
#include "stack.h"

int main(){
	int choice;
int num = 0;

while(num==0){
	printf(" 1. Insertion Sort \n 2. Bubble sort \n 3. Selection sort \n4. Addition");
	printf(" Enter your choice");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:printf(" Insertion sort\n");
				break;
		case 2:printf(" Bubble sort\n");
				break;
		case 3:printf(" Selection sort\n");
				break;
		case 4:printf(" Addition of 5 and 9 = %d\n",add(5,9));
				break;
		case 0:num=1;
				break;
		default:printf(" Enter valid choice\n");
		}
	}
	printf(" exited the menu.");
	return 0;
	
}
