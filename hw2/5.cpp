#include <iostream>
#include <vector>
#include <print>

// target - two sum задача, существуют ли два элемента 
// в отсортированном массиве, сумма которых равна target

void printArray(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::print("{} ", elem);
    }

    std::cout << std::endl;
}

bool target(std::vector<int>& vec, int target){
    int size = vec.size();
    int low{0};
    int high{size - 1};

    while(low<=high){
        if(vec[low]+vec[high] < target){
            low++;
        } else if (vec[low] + vec[high] > target){
            high--;
        } else{
            std::cout << vec[low] << " " <<vec[high] << std::endl;
            return true;
        }
    }

    std::cout << "No such elements" << std::endl;
    return false;
}

int main() {
    size_t n;
    int tar;
    std::cin >> n >> tar;

    std::vector<int> vec;

    int tmp;
    for (int i = 0;i < n;i++) {
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::cout << "Array:" << std::endl;
    printArray(vec);

    std::vector<int>& ref = vec;

    std::cout << "Target numbers:" << std::endl;
    target(ref, tar);
}