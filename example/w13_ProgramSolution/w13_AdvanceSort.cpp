#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime> 
using namespace std;
#define SIZE 5
#define Range 50

void showData(int [],int);
void copyArr(int *, int *);
void mergeSort(int [], int, int);
void merge(int [], int, int, int);
void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int *, int *);

int main(void){
    //random
    int DataBef[SIZE],DataAft[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
    	DataBef[i]=rand()%Range;
	}
		
	cout <<"\n";
	cout << "Merge sort:\n";
	showData(DataBef,0);
	cout <<endl;
	copyArr(DataAft, DataBef);
	mergeSort(DataAft, 0, SIZE-1);
	
	cout <<"\n";
	cout << "Quick sort:\n";
	showData(DataBef,0);
	cout <<endl;
	copyArr(DataAft, DataBef);
	quickSort(DataAft, 0, SIZE-1);
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
	return ;
}
void copyArr(int *p1, int *p2){
	for(int i=0;i<SIZE;i++){
		p1[i]=p2[i];
	}
	return ;
}
void mergeSort(int arr[], int left, int right){
	if(left>=right)
		return;
	else{
		int mid=left+ (right-left)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
void merge(int arr[], int l, int m, int r){
	int i, j, k; 
    int n1=m-l+1, n2=r-m; 
    int L[n1], R[n2]; 
    for (i=0; i<n1; i++) 
        L[i]=arr[l+i]; 
    for (j=0; j<n2; j++) 
        R[j]=arr[m+1+j]; 
        
    i=0;  j=0;   k=l;
    while(i<n1 && j<n2){ 
        if(L[i]<=R[j]){ 
            arr[k]=L[i]; 
            i++; 
        } 
        else{ 
            arr[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
    while(i<n1) { 
        arr[k]=L[i]; 
        i++; 
        k++; 
    } 
    while(j<n2) { 
        arr[k]=R[j]; 
        j++; 
        k++; 
    } 
    showData(arr,1);
    cout <<"=== " << l <<" - " <<m <<" - " <<r <<endl;
    return;
}
void quickSort(int arr[], int low, int high){
	int p;
	if(low < high){
		p=partition(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
	}
	return ;
}
int partition(int arr[], int left, int right){
	int i, j;
 
    for(i=left+1, j=right;  ;){
        while(arr[i]<arr[left] && i<=right) 
            i++;
        while(arr[j]>arr[left]) 
            j--;
        if(i>=j) {
            break;
        }
        swap(&arr[i++], &arr[j--]);
    }
    swap(&arr[left], &arr[j]);
    showData(arr,1);
    cout <<"=== " << left <<" - " <<right <<endl;
	return j;
}
void swap(int *p1, int *p2){
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
	return;
}

