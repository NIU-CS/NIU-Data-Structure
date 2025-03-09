#include <iostream>
#include <stack>
#include <vector>

using pair = std::pair<int, int>;
using v2i = std::vector<std::vector<int>>;

const int delta[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool is_valid(v2i &graph, pair p) {
    return p.first >= 0 && p.first < graph.size() && p.second >= 0 &&
           p.second < graph[0].size();
}

bool visit(v2i &graph, pair start, pair end) {
    bool flag = false;
    std::stack<pair> stk;
    std::vector<pair> path = {start};
    stk.push(start);
    graph[start.first][start.second] = 3;

    while (!stk.empty()) {
        pair current = stk.top();

        if (current == end) {
            path.push_back(current);
            for (auto& p : path) {
                graph[p.first][p.second] = 2;
            }
            flag = true;
        }

        bool foundNext = false;
        for (int i = 0; i < 4; i++) {
            int x = current.first + delta[i][0];
            int y = current.second + delta[i][1];

            if (is_valid(graph, {x, y}) && graph[x][y] == 0) {
                stk.push({x, y});
                graph[x][y] = 3;
                path.push_back(current);
                foundNext = true;
                break;
            }
        }

        if (!foundNext) {
            stk.pop();
            path.pop_back();
        }
    }
    return flag;
}

int main() {
    int n, m;
    std::cout << "請輸入迷宮長度與寬度：";
    std::cin >> n >> m;
    v2i graph(n, std::vector<int>(m));
    pair start, end;

    std::cout << "請輸入迷宮地圖:\n";
    for (auto &row : graph) {
        for (int &cell : row) {
            std::cin >> cell;
        }
    }

    do {
        std::cout << "請輸入起點座標：";
        std::cin >> n >> m;
        start = {n, m};
    } while (!is_valid(graph, start));

    do {
        std::cout << "請輸入終點座標：";
        std::cin >> n >> m;
        end = {n, m};
    } while (!is_valid(graph, end));
    // 加分：可額外判定使用者輸入的迷宮是否可走到終點。
    // 額外加分(多做)的部分
    std::cout << (visit(graph, start, end) ? "此迷宮有解\n" : "此迷宮無解\n");

    for (const auto &row : graph) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
