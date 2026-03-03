#include <iostream>
#include <vector>
#include <print>

// merge sorted arrays (with allocs)

void printArray(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
}

std::vector<int> merge(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> res;

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    res.reserve(size1 + size2);

    int i{ 0 }, j{ 0 };

    while (i < size1 && j < size2) {
        if (vec1[i] < vec2[j]) {
            res.push_back(vec1[i]);
            i++;
        }
        else if (vec1[i] >= vec2[j]) {
            res.push_back(vec2[j]);
            j++;
        }
    }

    while (i < size1) {
        res.push_back(vec1[i]);
        i++;
    }

    while (j < size2) {
        res.push_back(vec2[j]);
        j++;
    }

    return res;
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

    printArray(merge(vec1, vec2));
}