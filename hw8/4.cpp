#include <vector>

int piv_idx(const std::vector<int>& nums) {
    long long total = 0; // полная сумма 
    long long left = 0; // левая сумма

    for (int num : nums) {
        total += num;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (left == (total - left - nums[i])) {
            // если левая сумма = полная минус левая минус текущий элемент, то это опорный
            // элемент
            return i; // индекс поворота 
        }

        left += nums[i];  // расширили левую скмму
    }

    return -1; 
}