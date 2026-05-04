#include <vector>
#include <queue>

// найти k-й минимальный элемент

/*
    Сложность: проходим по массиву из N элементов, и выполняем вставки за log(K)
    Временная: Nlog(K)
    Память: O(K)
*/

int ksmall (std::vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap;
    
    for (int val : nums) {
        maxHeap.push(val);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}