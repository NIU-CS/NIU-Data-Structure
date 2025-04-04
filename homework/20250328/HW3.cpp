/*
hw3 by b1243010
can type any polynomial form like
"axb+cxd+ ..." or "a b c d ..."

Note: This program does not handle input exceptions.
    Ensure the input format is correct.
*/
#include <iostream>
#include <sstream>
#include <string>

struct ListNode {
    // 係數
    float val;
    // 指數
    int pow;
    ListNode *next;

    ListNode(float _val, int _pow) : val(_val), pow(_pow), next(nullptr) {};
    ListNode(float _val, int _pow, ListNode *_next)
        : val(_val), pow(_pow), next(_next) {};
};

class Queue {
  private:
    ListNode *_front, *_rear;

  public:
    Queue() : _front(nullptr), _rear(nullptr) {};
    ~Queue() {
        while (_front) {
            pop();
        }
    };

    void pop() {
        if (!_front) {
            return;
        }
        ListNode *tmp = _front;
        _front = _front->next;
        delete tmp;
        if (!_front) {
            _rear = nullptr;
        }
    }

    void push(float val, int pow) {
        if (!_rear) {
            _front = _rear = new ListNode(val, pow);
        } else {
            _rear = _rear->next = new ListNode(val, pow);
        }
    }

    ListNode *front() { return this->_front; };
    ListNode *rear() { return this->_rear; };
};

// string to polynomial by "a b c d ..."
// where a is the coefficient, b is the power, c is the coefficient, d is the
// power and so on
Queue makePoly(std::string s, bool n) {
    Queue poly;
    std::stringstream ss(s);
    int pow;
    float val;
    while (ss >> val >> pow) {
        poly.push(val, pow);
    }

    return poly;
}

// string to polynomial by "axb+cxd+..."
Queue makePoly(std::string s) {
    Queue poly;
    if (s.empty()) {
        return poly;
    }
    // 如果有空格，則使用空格分隔的 makePoly()
    if (s.find(' ') != std::string::npos) {
        return makePoly(s, true);
    }

    // 確保符號開頭
    if (s[0] != '+' && s[0] != '-') {
        s = "+" + s;
    }

    for (size_t i = 1, start = 0; i < s.size(); i++) {
        for (; i < s.size() && s[i] != '+' && s[i] != '-'; i++) {
        }
        std::string subs = s.substr(start, i - start);
        size_t xpos = subs.find('x');
        float val;
        int pow;

        if (xpos != std::string::npos) {
            val = xpos == 0 ? 1.0 : std::stof(subs.substr(0, xpos));
            pow =
                xpos + 1 >= subs.size() ? 1 : std::stoi(subs.substr(xpos + 1));
        } else {
            pow = 0;
            val = std::stof(subs);
        }
        poly.push(val, pow);
        start = i;
    }

    return poly;
}

// calculate polynomial
Queue calPoly(Queue &a, Queue &b, char op) {
    ListNode *pa = a.front(), *pb = b.front();
    Queue result;

    while (pa && pb) {
        if (pa->pow == pb->pow) {
            result.push(pa->val + (op == '-' ? -(pb->val) : pb->val), pa->pow);
            pa = pa->next;
            pb = pb->next;
        } else if (pa->pow > pb->pow) {
            result.push(pa->val, pa->pow);
            pa = pa->next;
        } else {
            result.push(op == '-' ? -(pb->val) : pb->val, pb->pow);
            pb = pb->next;
        }
    }
    while (pa) {
        result.push(pa->val, pa->pow);
        pa = pa->next;
    }
    while (pb) {
        result.push(op == '-' ? -(pb->val) : pb->val, pb->pow);
        pb = pb->next;
    }
    return result;
}

void printPoly(Queue a) {
    ListNode *ptr = a.front();
    while (ptr) {
        std::cout << ptr->val;
        if (ptr->pow) {
            std::cout << "x" << (ptr->pow == 1 ? "" : std::to_string(ptr->pow));
        }
        ptr = ptr->next;
        if (ptr && ptr->val >= 0) {
            std::cout << '+';
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string str;

    std::cout << "Enter the A(x): ";
    std::getline(std::cin, str);
    Queue a = makePoly(str);

    std::cout << "Enter the B(x): ";
    std::getline(std::cin, str);
    Queue b = makePoly(str);

    char op;
    std::cout << "Enter the operation (+ or -): ";
    std::cin >> op;

    std::cout << "Result of A(x) " << op << " B(x): ";
    printPoly(calPoly(a, b, op));

    return 0;
}
