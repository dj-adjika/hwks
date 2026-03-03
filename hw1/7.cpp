#include <iostream>
#include <vector>
#include <print>

// отсортировать массив так, чтобы нули стояли в конце 
// но при этом чтобы относительный порядок других не изменился.

// решили через два указателя, как в предыдущей задаче

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

    int p_valid{ 0 };
    int p_tmp{ 0 };

    while (p_tmp < size) {
        if (vec[p_tmp] != 0) {
            swap(vec[p_valid], vec[p_tmp]);
            p_valid++;
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