#include <iostream>
#include <vector>
#include <print>

// LeetCode - Sort Colors - Флаг Нидерландов
// Отсортировать массив из 0, 1, 2

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

    int low{0}; // указатель на позицию, где должен стоять след 0 (начало)
    int mid{0}; // текущий элемент
    int high{static_cast<int>(size - 1)}; // указатель на позицию, где должна стоять след 2 (конец)

    while (mid <= high){
        switch (vec[mid]){
        case 0:
            swap(vec[mid], vec[low]);
            low++; 
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(vec[mid], vec[high]);
            high--;
            break;
        }
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