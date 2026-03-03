#include <iostream>
#include <vector>
#include <print>

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

void make_unique(std::vector<int>& vec) {
    int slow{0};
    int fast{1};

    while(fast < vec.size()){
        if (vec[fast] != vec[slow]){
            slow++;
            vec[slow] = vec[fast];
        } 
        fast++;
    }

    slow++; // чтобы сместиться с последнего уникального элемента

    while (slow < vec.size()){
        vec[slow] = 0;
        slow++;
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

    std::vector<int>& ref = vec;

    make_unique(ref);

    std::cout << "After:" << std::endl;
    printArray(vec);
}