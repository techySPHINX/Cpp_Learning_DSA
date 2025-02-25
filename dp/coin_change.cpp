//given a set of coins and a target sum , find the minimun numbers of coins required to make the chnage

#include <iostream>
#include <vector>
#include <limits>

int minCoins(std::vector<int>& coins, int amount){
    int n = coins.size();
    std::vector<int> dp(amount+q,sd::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = std::min(dp[i], 1+dp[i-coins[j]]);
            }
            
        }
        
    }

    return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
    
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << minCoins(coins, amount) << std::endl;
    return 0;
}