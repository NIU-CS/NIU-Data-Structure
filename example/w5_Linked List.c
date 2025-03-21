#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *nextPtr;
};
void displayNode(struct node *H);
void deleteNode(struct node *H);

int main(void){
	struct node *head=NULL;
	struct node *tail=NULL;
	
	int num;
	printf("insert? ");
	scanf("%d",&num);
	
	while(num!=0){
		struct node *newPtr;
		newPtr=malloc(sizeof(struct node));
		
		newPtr->value = num;
		newPtr->nextPtr = NULL;
		
		if(head==NULL){
			head=newPtr;
			tail=newPtr;		
		}
		else{
			tail->nextPtr=newPtr;
			tail=newPtr;
		}
		printf("insert? ");
		scanf("%d",&num);
	}
	
	//output
	displayNode(head);

	//delete
	int flag=0;
	struct node *tempPtr;
	printf("\ndelete? ");
	scanf("%d",&num);
	if(head==NULL)
		printf("List is empt\n");
	else{
		tail=head;
		if(tail->value==num){
			printf("value %d found\n", tail->value);
			flag=1;
			head=tail->nextPtr;
			free(tail);
		}
		else{
			tempPtr=tail->nextPtr;
			while(tempPtr->nextPtr!=NULL){
				if(tempPtr->value==num){
					printf("value %d found\n",tempPtr->value);
					flag=1;
					tail->nextPtr=tempPtr->nextPtr;
					free(tempPtr);
					break;
				}
				else{
					tempPtr=tempPtr->nextPtr;
					tail=tail->nextPtr;
				}
			}
			if(tempPtr->value == num){
				printf("value %d found\n",tempPtr->value);
				flag=1;
				tail->nextPtr=NULL;
				free(tempPtr); 
			}
			if(flag==0)
				printf("value %d not found\n",num);
		}	
	}
	
	system("pause");
	return 0;
}
void displayNode(struct node *H){
	struct node *T;
	if(H==NULL)
		printf("List is empty\n");
	else{
		printf("List is ");
		T = H;
		while(T!=NULL){
			printf("%d \t",T->value);
			T=T->nextPtr;
		}
	}
	return;
}
/*
void deleteNode(struct node *H){
	
}
*/







