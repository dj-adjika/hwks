#include <print>
#include <vector>

// найти произведение максимального и минимального элемента 
// в BST, заданном в виде массива

// Если BST полное, то алгоритм такой, но если не полное, без восстановления в дерево почти не обойтись
// можно попробовать как-то через std::optional, но я пока до конца в этом не уверен

template<typename T>
int max_min_mul(std::vector<T>& vec) {
    if (vec.empty()) {
        return -1;
    }

    int min_idx = 0;
    while (2 * min_idx + 1 < vec.size()) {
        min_idx = 2 * min_idx + 1;
    }

    int max_idx = 0;
    while (2 * max_idx + 2 < vec.size()) {
        max_idx = 2 * max_idx + 2;
    }
    
    std::println("min = {}, max = {}", vec[min_idx], vec[max_idx]);
    return vec[min_idx] * vec[max_idx];
}

int main() {
    std::vector<int> vec = {8, 3, 10, 1, 6, 9, 12};

    std::println("{}",max_min_mul(vec));
}