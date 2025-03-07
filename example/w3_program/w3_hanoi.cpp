#include <cstdlib>
#include <iostream>
using namespace std;
void hanoi(int n, char S, char M, char E);
int c = 0;

int main(void) {
    int n;
    cout << "input n:";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << "count:" << c << endl;
    system("pause");
    return 0;
}
void hanoi(int n, char S, char M, char E) {
    if (n == 1) {
        cout << "move " << S << " to " << E << endl;
        c++;
        return;
    } else {
    }
}
