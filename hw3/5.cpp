#include <vector>
#include <iostream>
#include <print>
#include <map>

// по заданному вектору и числу target найти пару чисел, в сумме дающих target

// Сложность - O(n), два раза проходим по вектору, операции с map - O(1)
// Двойной цикл не нужен, map после инициализации хранит все элементы вектора и мы 
// за O(1) можем проверить наличие нужного элемента

std::pair<int, int> find_target(std::vector<int>& vec, int target) {
    std::map<int, bool> m1;

    for (const auto& elem : vec) {
        m1[elem] = true;
    }

    for (const auto& elem : vec) {
        if (m1.contains(target - elem)) {
            return { elem, target - elem };
        }
    }

    return {};
}

int main() {
    int target{};
    std::cin >> target;

    std::vector<int> vec;
    int tmp{};

    while (std::cin >> tmp){
        vec.push_back(tmp);
    }

    std::println("{} {} {}", target, find_target(vec, target).first, find_target(vec, target).second);
}