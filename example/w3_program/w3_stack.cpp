#include <cstdlib>
#include <iostream>
#define SIZE 5

int choice(void);
void printArr(int[]);
void push(int[], int);
int pop(int[]);
bool IsFull(void);
bool IsEmpty(void);
int num = 0;

int main(void) {
    int arr[SIZE] = {0}, ch, data;
    while (true) {
        printArr(arr);
        ch = choice();
        if (ch == 3) break;
        if (ch == 1) {
            std::cout << "Data:";
            std::cin >> data;
            push(arr, data);
        }
        if (ch == 2) data = pop(arr);
    }
    system("pause");
    return 0;
}

int choice(void) {
    int ans;
    std::cout << "1.push\n" << "2.pop\n" << "3.Exit\n" << "choice:";
    std::cin >> ans;
    return ans;
}

void printArr(int a[]) {
    std::cout << "\n" << "Array:";
    for (int i = 0; i < num; i++) std::cout << a[i] << "  ";
    std::cout << std::endl;
    return;
}

bool IsFull(void) {
    return (num != SIZE - 1);
}

bool IsEmpty(void) {
    return num == 0;
}

void push(int a[], int data) {
    if (IsFull()) {
        std::cout << "Stack is full!" << std::endl;
        return;
    }
    a[num++] = data;
    return;
}

int pop(int a[]) {
    if (IsEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
    num--;
    return a[num];
}
