//C++: use Linked list for the implementation of stack

#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int value;
	struct node *nextPtr;
};
typedef struct node NODE;
NODE *Top=NULL;
	
int choice(void);
void showList();
void push(int);
int pop();
int main(void){
	int ch, data;	
	while(true){
		showList();
		ch=choice();
		if(ch==3)
			break;
		if(ch==1){
			cout <<"Data:";
			cin >>data;
			push(data);
		}
		if(ch==2)
			data=pop();		
	}
	system("pause");
	return 0;
}
int choice(void){
	int ans;
	cout <<"1.push\n"<<"2.pop\n"<<"3.Exit\n"<<"choice:";
	cin >>ans;
	return ans; 
}
void showList(){
	NODE *ptr=Top;
	cout<<"\n"<<"List(top to bottom):";
	if(Top==NULL)
		cout <<"empty!\n";
	else{
		//???
		
		
		cout <<endl;
	} 	
	return;
}

void push(int data){
	NODE *newNode=new NODE;
	newNode->value = data;
	if(Top==NULL){
		//???
				
	}	
	else{
		//???
		
	}	
	//???
			 					
	return ;
} 
int pop(){
	NODE *ptr=Top;
	if(Top==NULL) //IsEmpty( )
		cout<<"\n"<<"List is empty!\n";	
	else{		
		if(ptr->nextPtr==NULL){ //only one data
			//???
		}
		else{
			//???
		
		}			
		free(ptr);
	}	
	return 0;	
} 
