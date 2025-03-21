#include <iostream>
#include <vector>

int ackerman(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackerman(m - 1, 1);
    return ackerman(m - 1, ackerman(m, n - 1));
}

int main() {
    int ans = ackerman(3, 3);

    std::cout << ans << std::endl;
    return 0;
}
