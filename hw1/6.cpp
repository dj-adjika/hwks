#include <iostream>
#include <vector>
#include <print>

// Передвинуть чётные числа вперёд на неотсортированном массиве
// Сохранить ИХ относительный порядок

void swap(int& pa, int& pb) {
    int tmp = pa;
    pa = pb;
    pb = tmp;
}

void printArray(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
}

void sort(std::vector<int>& vec) {
    size_t size = vec.size();

    int p_even = 0;
    int p_tmp = 0;

    while (p_tmp < size) {
        if (!(vec[p_tmp]&0x1) && (p_tmp != p_even)) {
            swap(vec[p_even], vec[p_tmp]);
            p_even++;
        }
        p_tmp++;
    }
}

int main() {
    size_t n;
    std::cin >> n;

    std::vector<int> vec;

    int tmp;
    for (int i = 0;i < n;i++) {
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::cout << "Before:" << std::endl;
    printArray(vec);

    sort(vec);

    std::cout << "After:" << std::endl;
    printArray(vec);
}