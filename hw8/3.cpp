#include <vector>
#include <unordered_map>

// если одна и та же префиксная сумма встречается два раза, то значит элементы между 
// позициями дают в сумме ноль

int f(const std::vector<int>& nums) {
    int prefixSum = 0;
    int maxLen = 0;
    
    std::unordered_map<int, int> indexMap;
    indexMap[0] = -1; // сумма 0 на "позиции" -1

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += (nums[i] == 0) ? -1 : 1; // замена 0 на -1

        if (indexMap.find(prefixSum) != indexMap.end()) {
            maxLen = std::max(maxLen, i - indexMap[prefixSum]);
            // если уже встретили, то считаем длину текущего подмассива
        } else {
            indexMap[prefixSum] = i; // сохраняем первое вхождение для max длины 
        }
    }

    return maxLen;
}