#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"admin.c"


int main(){
	int ch;
	do{
		square0:
		printf("\n1. Trainer");
		printf("\n2. Trainee");
		printf("\n3. Admin");
		printf("\n4. Exit");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				// trainer();
				break;
			case 2:
				// trainee();
				break;
			case 3:
				admin();
				break;
		}
	}while(ch != 4);
}