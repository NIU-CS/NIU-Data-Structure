#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <algorithm>
using namespace std;
#define SIZE 10
#define Range 50

void showData(int [],int);
void bubbleSort(int []);
void insertSort(int []);
void selectSort(int []);
void swap(int *, int *);
void copyArr(int *, int *);
int main(void){
    //random
    int DataBef[SIZE],DataAft[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
    	DataBef[i]=rand()%Range;
	}
	showData(DataBef,0);
	cout << "Algorithm-sort:\n";
	copyArr(DataAft, DataBef);
	sort(DataAft, DataAft+SIZE);
	showData(DataAft,0);
	
	cout <<"\n";
	cout << "Bubble sort:\n";
	showData(DataBef,0);
	copyArr(DataAft, DataBef);
	bubbleSort(DataAft);
	
	cout <<"\n";
	cout << "Insert sort:\n";
	showData(DataBef,0);
	copyArr(DataAft, DataBef);
	insertSort(DataAft);
	
	cout <<"\n";
	cout << "Selection sort:\n";
	showData(DataBef,0);
	copyArr(DataAft, DataBef);
	selectSort(DataAft);
 	system("PAUSE");	
	return 0;
}
void showData(int arr[], int n){
	if(n==0)
		cout <<setw(7) <<"round" <<endl;
	cout <<setw(7) <<n <<"-";
	for(int i=0;i<SIZE;i++){
		cout << setw(3)<< arr[i] <<" ";
	} 
	cout <<endl;
	return ;
}
void copyArr(int *p1, int *p2){
	for(int i=0;i<SIZE;i++){
		p1[i]=p2[i];
	}
	return ;
}
void swap(int *p1, int *p2){
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
	return;
}
void bubbleSort(int arr[]){
	for(int pass= ??? ;pass< ??? ;pass++){   //�ն�g�j�馸�� 
		for(int j= ??? ;j< ???;j++){        //�ն�g�j�馸�� 
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
		showData(arr,pass);
	}
	return ;
}
void insertSort(int arr[]){
	int temp, pass, j;
	for(pass=1;pass<SIZE;pass++){
		temp=arr[pass];
		for(j=pass;j>0 && arr[j-1]>temp;j--){
			if(arr[j-1]>temp)
				arr[j]=arr[j-1];				
		}
		arr[j]=temp;
		showData(arr,pass);
	}
	return ;
}
void selectSort(int arr[]){
	int idx,max;
	for(int pass=??? ; ????; ???){   //�ն�g�j�馸��  
		max=arr[0];
		idx=0;
		for(int j=0;j<=pass;j++){
			if(arr[j]>max){
				max=arr[j];
				idx=j;
			}
		}
		swap(&arr[pass],&arr[idx]);
		showData(arr,SIZE-pass);
	}
	return ;
}

