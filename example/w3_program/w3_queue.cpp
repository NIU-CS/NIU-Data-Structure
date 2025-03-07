#include <cstdlib>
#include <iostream>
#define SIZE 5
using namespace std;
int choice(void);
void printArr(int[]);
bool IsFull(void);
bool IsEmpty(void);
void Enqueue(int[], int);
int Dequeue(int[]);
int front = -1, rear = -1;

int main(void) {
    int arr[SIZE] = {0}, ch, data;
    while (true) {
        printArr(arr);
        ch = choice();
        if (ch == 3) break;
        if (ch == 1) {
            cout << "Data:";
            cin >> data;
            Enqueue(arr, data);
        }
        if (ch == 2) data = Dequeue(arr);
    }
    system("pause");
    return 0;
}
int choice(void) {
    int ans;
    cout << "1.Add(EnQ)\n" << "2.Delete(DeQ)\n" << "3.Exit\n" << "choice:";
    cin >> ans;
    return ans;
}
void printArr(int a[]) {
    cout << "\n" << "Array:";
    for (int i = front + 1; i <= rear; i++) cout << a[i] << "  ";
    cout << endl;
    return;
}
bool IsFull(void) {
    if ()
        return false;
    else
        return true;
}
bool IsEmpty(void) {
    if ()
        return true;
    else
        return false;
}
void Enqueue(int a[], int data) { return; }
int Dequeue(int a[]) {}
