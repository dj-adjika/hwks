#include <iostream>
#include <vector>
#include <print>

// sort array of 0 and 1

// можно посчитать количество единиц и записать в конец число единиц

// это же решение предлагает реализацию двух указателей: с начала и с конца

void swap(int& pa, int& pb) {
    int tmp = pa;
    pa = pb;
    pb = tmp;
}

void sort(std::vector<int>& vec) {
    int size = vec.size();

    int p1 = 0, p2 = size - 1;
    while (p1 < p2) {
        if (vec[p1] == 0) {
            p1++;
        } else if (vec[p2] == 1) {
            p2--;
        } else {
            swap(vec[p1], vec[p2]);
            p1++;
            p2--;
        }
    }
}

void printArray(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
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