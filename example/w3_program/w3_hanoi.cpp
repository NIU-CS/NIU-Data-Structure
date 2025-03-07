#include <cstdlib>
#include <iostream>

void hanoi(int n, char S, char M, char E);
int c = 0;

int main(void) {
    int n;
    std::cout << "input n:";
    std::cin >> n;
    hanoi(n, 'A', 'B', 'C');
    std::cout << "count:" << c << std::endl;
    system("pause");
    return 0;
}

void hanoi(int n, char S, char M, char E) {
    if (n == 1) {
        std::cout << "move " << S << " to " << E << std::endl;
        c++;
        return;
    } else {
    }
}
