#include <vector>
#include <queue>

// merge K sorted arrays

// Сложность: 
//     Временная - O(Nlog(K)), так как вставка в кучу производится за log(K), 
//     потому что в куче одновременно находится не более K элементов
//     Память - O(N+K) - учли длину res массива

struct Element {
    int val, arrayIdx, elementIdx;
    
    bool operator>(const Element& other) const { 
        return val > other.val; 
    }
};

std::vector<int> mergeKArrays(std::vector<std::vector<int>>& arrays) {
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
    
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }
    
    std::vector<int> result;
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        
        result.push_back(current.val);
        
        if (current.elementIdx + 1 < arrays[current.arrayIdx].size()) {
            minHeap.push({
                arrays[current.arrayIdx][current.elementIdx + 1], 
                current.arrayIdx, 
                current.elementIdx + 1
            });
        }
    }

    return result;
}