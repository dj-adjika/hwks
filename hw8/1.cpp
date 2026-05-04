#include <vector>

// используем метод скользящего окна

// сначала вычисляем сумму одного окна, а затем "сдвигаем" его: вычитаем ушедший
// элемент и добавляем пришедший (при сдвиге)

long long maxSubarrSum(const std::vector<int>& arr, int k) {
    if (arr.size() < k) {
        return 0;
    }

    long long curr_sum = 0;
    
    for (int i = 0; i < k; i++) {
        curr_sum += arr[i];
    }

    long long maxSum = curr_sum;

    for (int i = k; i < arr.size(); i++) {
        curr_sum = curr_sum - arr[i - k] + arr[i];
        maxSum = std::max(maxSum, curr_sum);
    }

    return maxSum;
}