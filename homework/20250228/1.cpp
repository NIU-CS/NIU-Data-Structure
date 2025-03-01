#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "請輸入奇數 n：";
    cin >> n;

    // 若 n 不是奇數，可根據需求自行做處理，這裡僅簡單判斷
    if (n <= 0 || n % 2 == 0) {
        cout << "n 必須為正的奇數！" << endl;
        return 0;
    }

    // 建立 n*n 的二維陣列，預設填 0
    int** magicSquare = new int*[n];
    for (int i = 0; i < n; i++) {
        magicSquare[i] = new int[n];
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    // Siamese method 規則：
    // 1. 將 1 放在最上列中間欄位
    // 2. 下一個數字 (i.e. 2, 3, ...) 的位置是「上一列、下一欄」
    //    - 若超出上方，則從最下列繼續
    //    - 若超出右方，則從最左欄繼續
    // 3. 如果該位置已被填或同時超出上方與右方，則移回前一個位置的正下方

    int num = 1;      // 要填入的數字
    int row = 0;      // 最上列
    int col = n / 2;  // 中間欄

    while (num <= n * n) {
        magicSquare[row][col] = num;  // 填入數字
        num++;

        // 計算下一個位置 (r, c) = (row - 1, col + 1)
        int newRow = (row - 1 + n) % n;  // 上一列，若超出就循環至最下列
        int newCol = (col + 1) % n;      // 下一欄，若超出就循環至最左欄

        // 若該位置已經被填，或兩邊都超界(其實已經在 % n 處理)
        // 就把下一個數字放在原位置的下一列
        if (magicSquare[newRow][newCol] != 0) {
            row = (row + 1) % n;  // 移到正下方
        } else {
            row = newRow;
            col = newCol;
        }
    }

    // 輸出魔術方陣
    cout << "產生的 " << n << " x " << n << " 魔術方陣：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 為了對齊排版，使用 setw(4) 略作美觀輸出
            cout << setw(4) << magicSquare[i][j];
        }
        cout << endl;
    }

    // 釋放記憶體
    for (int i = 0; i < n; i++) {
        delete[] magicSquare[i];
    }
    delete[] magicSquare;

    return 0;
}
