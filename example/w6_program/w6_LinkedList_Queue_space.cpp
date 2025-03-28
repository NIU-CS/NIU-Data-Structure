//C++: use Linked list for the implementation of Queue 

#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	int value;
	struct node *nextPtr;
};
typedef struct node NODE;
NODE *front=NULL;
NODE *rear=NULL;
	
int choice(void);
void showList();
void Enqueue(int);
int Dequeue();

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
			Enqueue(data);
		}
		if(ch==2)
			data=Dequeue();		
	}
	system("pause");
	return 0;
}
int choice(void){
	int ans;
	cout <<"1.Add(EnQ)\n"<<"2.Delete(DeQ)\n"<<"3.Exit\n"<<"choice:";
	cin >>ans;
	return ans; 
}
void showList(){
	NODE *ptr=front;
	cout<<"\n"<<"List(front to rear):";
	if(front==NULL)
		cout <<"empty!\n";
	else{
		//???
		
		
		cout <<endl;
	} 	
	return;
}

void Enqueue(int data){
	NODE *newNode=new NODE;
	newNode->value = data;
	newNode->nextPtr=NULL;
	if(front==NULL){  //IsEmpty( )
		//???
		
		
	}	
	else{
		//???
		
		
	}						
	return ;
} 

int Dequeue(){
	NODE *ptr=front;
	if(front==NULL) //IsEmpty( )
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
