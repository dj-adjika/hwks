#include <iostream>
#include <vector>
#include <algorithm>
#include <print>

// найти корень числа (ближайшее целое число)

// log(n), так как на каждом шаге мы отбрасываем половину оставшихся чисел
// на каждом шаге уменьшаем расстояние между l и вдвое, следовательно, 
// количество итераций будет log_2(n), где n - это значение val

int root(int val) {
    int l = 0;
    int r = val;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (mid * mid == val) {
            return mid;
        }
        else if (mid * mid < val) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    std::vector vec{ 196, 254, 1, 100, 3 };
    for (const auto& elem : vec){
        std::println("Корень числа {}: {}", elem, root(elem));
    }
}