/*
程式名稱：多項式加減法運算（使用鏈結串列實作）

說明：
本程式可接受使用者輸入兩個多項式 A(x) 與 B(x)，並指定要執行加法或減法，
最後輸出結果多項式。多項式使用鏈結串列結構實作，每個節點代表一項。

輸入說明（困難版格式）：
每個多項式輸入請以「數學表示法」直接輸入，例如：
    輸入 A(x)：5x^4+6.1x^2+2.9x+6
    輸入 B(x)：9x^5-3.2x^2-4x-5

注意事項：
1. 可以省略 x 的次方，例如「+2.9x」等同於「+2.9x^1」
2. 常數項無需加 x，例如「+6」等同於「+6x^0」
3. 可省略係數為 1 的數字，例如「-x^3」等同於「-1x^3」

運算符號輸入：
請輸入一個字元代表要執行的運算：「+」 或 「-」

輸出說明：
程式會顯示 A(x) 與 B(x) 的運算結果，例如：
    A(x) + B(x) = 9x^5+5x^4+2.9x^2-1.1x+1
*/

#include <iostream>
#include <memory>
#include <regex>
#include <string>

struct Term {
    double coef;
    int exp;
    std::unique_ptr<Term> next;
    Term(double c, int e) : coef(c), exp(e), next(nullptr) {}
};

class Polynomial {
public:
    Polynomial() : head(nullptr) {}

    void insert(double coef, int exp) {
        if (coef == 0) return;

        auto new_term = std::make_unique<Term>(coef, exp);

        if (!head || head->exp < exp) {
            new_term->next = std::move(head);
            head = std::move(new_term);
        } else {
            Term* current = head.get();
            while (current->next && current->next->exp > exp) {
                current = current->next.get();
            }

            if (current->exp == exp) {
                current->coef += coef;
                if (current->coef == 0) remove(exp);
            } else if (current->next && current->next->exp == exp) {
                current->next->coef += coef;
                if (current->next->coef == 0) current->next = std::move(current->next->next);
            } else {
                new_term->next = std::move(current->next);
                current->next = std::move(new_term);
            }
        }
    }

    void remove(int exp) {
        if (!head) return;
        if (head->exp == exp) {
            head = std::move(head->next);
            return;
        }

        Term* current = head.get();
        while (current->next && current->next->exp != exp) {
            current = current->next.get();
        }

        if (current->next && current->next->exp == exp) {
            current->next = std::move(current->next->next);
        }
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        Term* a = this->head.get();
        Term* b = other.head.get();

        while (a || b) {
            if (a && (!b || a->exp > b->exp)) {
                result.insert(a->coef, a->exp);
                a = a->next.get();
            } else if (b && (!a || b->exp > a->exp)) {
                result.insert(b->coef, b->exp);
                b = b->next.get();
            } else {
                result.insert(a->coef + b->coef, a->exp);
                a = a->next.get();
                b = b->next.get();
            }
        }

        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        Term* a = this->head.get();
        Term* b = other.head.get();

        while (a || b) {
            if (a && (!b || a->exp > b->exp)) {
                result.insert(a->coef, a->exp);
                a = a->next.get();
            } else if (b && (!a || b->exp > a->exp)) {
                result.insert(-b->coef, b->exp);
                b = b->next.get();
            } else {
                result.insert(a->coef - b->coef, a->exp);
                a = a->next.get();
                b = b->next.get();
            }
        }

        return result;
    }

    void print() const {
        Term* current = head.get();
        bool first = true;
        while (current) {
            if (!first && current->coef >= 0) std::cout << "+";
            if (current->exp == 0) std::cout << current->coef;
            else if (current->exp == 1) std::cout << current->coef << "x";
            else std::cout << current->coef << "x^" << current->exp;
            current = current->next.get();
            first = false;
        }
        if (first) std::cout << "0";
        std::cout << std::endl;
    }

private:
    std::unique_ptr<Term> head;
};

Polynomial parse_polynomial_string(const std::string& input) {
    Polynomial poly;
    std::regex term_pattern(R"(([+-]?\d*\.?\d*)(x(\^\d+)?)?)");
    auto terms_begin = std::sregex_iterator(input.begin(), input.end(), term_pattern);
    auto terms_end = std::sregex_iterator();

    for (std::sregex_iterator i = terms_begin; i != terms_end; ++i) {
        std::smatch match = *i;
        if (match.str().empty()) continue;

        std::string coef_str = match[1];
        std::string x_part = match[2];
        std::string exp_str = match[3];

        double coef = 0.0;
        int exp = 0;

        if (x_part.empty()) {
            coef = std::stod(coef_str);
            exp = 0;
        } else {
            if (coef_str.empty() || coef_str == "+") coef = 1;
            else if (coef_str == "-") coef = -1;
            else coef = std::stod(coef_str);

            if (exp_str.empty()) {
                exp = 1;
            } else {
                exp = std::stoi(exp_str.substr(1)); // 去掉 ^
            }
        }

        poly.insert(coef, exp);
    }

    return poly;
}

int main() {
    Polynomial A, B;
    std::cin.ignore(); // 清除 cin buffer
    std::string input;

    std::cout << "請輸入 A(x)：(格式如：5x^4+6.1x^2+2.9x+6)\n";
    std::getline(std::cin, input);
    A = parse_polynomial_string(input);

    std::cout << "請輸入 B(x)：(格式如：9x^5-3.2x^2-4x-5)\n";
    std::getline(std::cin, input);
    B = parse_polynomial_string(input);

    std::cout << "請輸入運算 (+ 或 -)：";
    char op;
    std::cin >> op;

    Polynomial result;
    if (op == '+') result = A + B;
    else if (op == '-') result = A - B;
    else {
        std::cout << "不支援的運算" << std::endl;
        return 1;
    }

    std::cout << "運算結果為：";
    result.print();

    return 0;
}
