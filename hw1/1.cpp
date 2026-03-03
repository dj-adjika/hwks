#include <iostream>
#include <vector>
#include <print>

// разворот части массива

// сложность - O(n)

void swap(int& pa, int& pb) {
    int tmp = pa;
    pa = pb;
    pb = tmp;
}

void printArray(std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
}

void reverseArray(std::vector<int>& vec, int left, int right) {
    while (left < right) {
        swap(vec[left], vec[right]);
        left++;
        right--;
    }
}

void rotateArray(std::vector<int>& vec, int k) {
    size_t size = vec.size();

    k %= size;

    reverseArray(vec, 0, size - 1);
    //printArray(vec);
    reverseArray(vec, 0, k - 1);
    //printArray(vec);
    reverseArray(vec, k, size - 1);
}

int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> vec;

    int tmp;
    for (int i = 0;i < n;i++) {
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::cout << "Before:" << std::endl;
    printArray(vec);

    std::cout << "ROTATING:" << std::endl;

    rotateArray(vec, k);
    printArray(vec);
}
