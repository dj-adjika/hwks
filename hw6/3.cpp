#include <vector>

// Используем ДП: dp[i] — минимальное количество монет для суммы i.
// Переход: для каждой монеты c, если берем её, то dp[i] = 1 + dp[i - c].
// Выбираем минимум среди всех доступных номиналов для каждой суммы.
// Сложность: O(amount * количество_монет).

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}