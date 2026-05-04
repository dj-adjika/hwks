#include <vector>
#include <unordered_map>

// map используется для хранения частот появления префиксных сумм
// если текущая prefix_sum - k уже есть в мапе, то существует подмассив с суммой k 

// сложность алгоритма = O(n) и по памяти и по времени

int subarraySum(const std::vector<int>& nums, int k) {
    int prefixSum = 0;
    int count = 0;

    std::unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    for (int num : nums) {
        prefixSum += num; 

        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }
    
        prefixCount[prefixSum]++;
    }

    return count;
}