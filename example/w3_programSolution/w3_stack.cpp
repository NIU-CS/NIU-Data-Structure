#include <iostream>
#include <cstdlib>
#define SIZE 5
using namespace std;
int choice(void);
void printArr(int []);
void push(int [], int);
int pop(int []);
bool IsFull(void);
bool IsEmpty(void);
int num=0;

int main(void){
	int arr[SIZE]={0},ch,data;
	while(true){
		printArr(arr);
		ch=choice();
		if(ch==3)
			break;
		if(ch==1){
			cout <<"Data:";
			cin >>data;
			push(arr,data);
		}
		if(ch==2)
			data=pop(arr);		
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
void printArr(int a[]){
	cout<<"\n"<<"Array:";
	for(int i=0;i<num;i++)
		cout <<a[i] <<"  ";
	cout <<endl;
	return;
}
bool IsFull(void){
	if(num<SIZE)
		return false;
	else
		return true;
}
bool IsEmpty(void){
	if(num==0)
		return true;
	else
		return false;
}
void push(int a[], int data){
	if(IsFull())
		cout <<"array is full\n";
	else
		a[num++]=data;				
	return ;
} 
int pop(int a[]){
	if(IsEmpty()){
		cout <<"array is empty\n";
		return -1;
	}
	else
		return a[num--];
} 
