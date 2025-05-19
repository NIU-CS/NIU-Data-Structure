#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// Selection Sort
void selection_sort(std::vector<int>& a) {
    const size_t n = a.size();
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t min_i = i;
        for (size_t j = i + 1; j < n; ++j)
            if (a[j] < a[min_i])
                min_i = j;
        std::swap(a[i], a[min_i]);
    }
}

// Merge Sort
void merge(std::vector<int>& a, int l, int m, int r) {
    std::vector<int> L(a.begin() + l, a.begin() + m + 1);
    std::vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        a[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
    }
    while (i < (int)L.size()) a[k++] = L[i++];
    while (j < (int)R.size()) a[k++] = R[j++];
}

void merge_sort_rec(std::vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort_rec(a, l, m);
    merge_sort_rec(a, m + 1, r);
    merge(a, l, m, r);
}

void merge_sort(std::vector<int>& a) {
    if (!a.empty()) merge_sort_rec(a, 0, a.size() - 1);
}

// Quick Sort
int partition(std::vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] < pivot) {
            std::swap(a[++i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort_rec(std::vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort_rec(a, low, pi - 1);
        quick_sort_rec(a, pi + 1, high);
    }
}

void quick_sort(std::vector<int>& a) {
    if (!a.empty()) quick_sort_rec(a, 0, a.size() - 1);
}

// Radix Sort (LSD for non-negative ints)
void radix_sort(std::vector<int>& a) {
    if (a.empty()) return;
    int max_val = *std::max_element(a.begin(), a.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::vector<int> output(a.size());
        int count[10] = {0};
        for (int v : a) count[(v / exp) % 10]++;
        for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
        for (int i = (int)a.size() - 1; i >= 0; --i) {
            int digit = (a[i] / exp) % 10;
            output[--count[digit]] = a[i];
        }
        a = std::move(output);
    }
}

int main() {
    std::mt19937_64 rng(std::random_device{}());
    std::cout << "n,Selection(ms),Merge(ms),Quick(ms),Radix(ms)\n";
    for (int n = 1; n <= 1048576; n *= 2) {
        std::uniform_int_distribution<int> dist(0, n);

        std::vector<int> original;
        original.reserve(n);
        for (int i = 0; i < n; ++i) {
            original.push_back(dist(rng));
        }

        auto measure = [&](auto f){
            auto a = original;
            auto t1 = std::chrono::high_resolution_clock::now();
            f(a);
            auto t2 = std::chrono::high_resolution_clock::now();
            using ms = std::chrono::duration<double, std::milli>;
            return ms(t2 - t1).count();
        };

        double t_sel = measure(selection_sort);
        double t_mer = measure(merge_sort);
        double t_qui = measure(quick_sort);
        double t_rad = measure(radix_sort);

        std::cout << n
                  << "," << t_sel
                  << "," << t_mer
                  << "," << t_qui
                  << "," << t_rad
                  << "\n";
    }
    return 0;
}
