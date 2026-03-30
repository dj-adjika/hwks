#include <print>
#include <iostream>

// "очень лёгкая задача" - найти минимальное время, за которое два принтера 
// со скоростями x и y распечатают n страниц

int process_time(int n, int x, int y) {
    int l = 0;
    int r = std::max(x, y) * (n - 1); // максимальная временная граница

    while (l + 1 < r) {
        int mid = (r + l) / 2;

        if (mid/x + mid/y < n - 1){ // текущее количество страниц
            l = mid;
        } else {
            r = mid;
        }
    }

    return r + std::min(x, y); // время копирования первого листа + остальные n - 1
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::println("Минимальное время: {}", process_time(n, x, y));
}