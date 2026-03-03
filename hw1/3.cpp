#include <iostream>
#include <vector>
#include <print>

// merge sorted arrays (no allocs): 3 pointers

void printArray(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
}

void merge(std::vector<int>& v1, std::vector<int>& v2){
    size_t size1 = v1.size();
    size_t size2 = v2.size();

    int p1 = size1 - size2 - 1; // указатель на начало нулей
    int p2 = size2 - 1; // указатель по второму массиву
    int p3 = size1 - 1; // результирующий, по которому пишем в первый массив(вектор)

    while (p2 >= 0){
        if (p1 >= 0 && v1[p1] > v2[p2]){
            v1[p3] = v1[p1];
            p1--;
        } else {
            v1[p3] = v2[p2];
            p2--;
        }
        p3--;
    }
}

int main() {
    size_t n1, n2;
    std::vector<int> vec1;

    std::cin >> n1 >> n2;

    int tmp;
    for (int i = 0;i < n1;i++) {
        std::cin >> tmp;
        vec1.push_back(tmp);
    }

    std::vector<int> vec2;

    for (int i = 0;i < n2;i++) {
        std::cin >> tmp;
        vec2.push_back(tmp);
    }

    merge(vec1, vec2);

    printArray(vec1);
}