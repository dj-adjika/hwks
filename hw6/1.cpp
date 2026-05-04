#include <vector>

// найти длину наибольшей возрастающей подпоследовательности

// пока элементы строго возрастают, увеличиваем текущую максимальную длину, 
// иначе сбрасываем счётчик до 1

int find_len(std::vector<int>& nums) {
    if (nums.empty()){
        return 0;
    }

    int res_max = 1, curr_max = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i-1]) {
            curr_max++;
        } else {
            curr_max = 1;
        }

        res_max = std::max(res_max, curr_max);
    }

    return res_max;
}