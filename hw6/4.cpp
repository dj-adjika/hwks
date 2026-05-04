#include <string>
#include <vector>

// найти самый длинный палиндром

// Используем матрицу ДП: dp[i][j] истинно, если подстрока от i до j — палиндром.
// База: одиночные символы (dp[i][i]) и пары одинаковых символов (dp[i][i+1]).
// Переход: s[i..j] — палиндром, если s[i] == s[j] и внутренняя часть dp[i+1][j-1] истинна.
// Сложность: O(n^2) по времени и памяти.

std::string f(std::string s) {
    int n = s.length();
    if (n < 2) return s;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int len = 2; len <= n; len++) { 
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2 || dp[i+1][j-1]) {
                    dp[i][j] = true;

                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
    }

    return s.substr(start, maxLen);
}