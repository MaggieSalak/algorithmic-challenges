// 1: With recursion

class Solution {
public:
    
    int get_min(int res, int cur) {
        if (res == -1)
            return cur;
        return min(res, cur);
    }
    
    void calc(const vector<int>& coins, int index, int amountLeft, int coinsUsed, int& minCoins) {
        if (amountLeft == 0) {
            minCoins = get_min(minCoins, coinsUsed);
        } 
        if (index < 0) {
            return;
        }
        
        for (int i = amountLeft / coins[index]; i >= 0; --i) {
            int newAmount = amountLeft - i * coins[index];
            calc(coins, index-1, newAmount, coinsUsed + i, minCoins);
        }
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int minCoins = -1;
        calc(coins, coins.size() - 1, amount, 0, minCoins);
        return minCoins;
    }
};

// 2: With dynamic programming, complexity O(Amount * CoinCount)

class Solution {
public:
    int getMin(int curVal, int newVal) {
        if (curVal == -1) {
            return newVal;
        }
        if (newVal == -1) {
            return curVal;
        }
        return min(curVal, newVal);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        int coinCount = coins.size();
        vector<vector<int>> val(amount+1, vector<int>(coinCount, -1));
        vector<int> minCoinCounts(amount+1, -1);
        
        for (int value = 1; value <= amount; ++value) {
            int minCoinCount = -1;
            
            for (int coinIndex = 0; coinIndex < coinCount; ++coinIndex) {
                int coin = coins[coinIndex];
                if (value - coin == 0) {
                    val[value][coinIndex] = 1;
                } else if (value - coin > 0) {
                    int mn = minCoinCounts[value - coin];
                    if (mn == -1) {
                        val[value][coinIndex] = -1;
                    } else {
                        val[value][coinIndex] = mn + 1;
                    }
                }
                minCoinCount = getMin(minCoinCount, val[value][coinIndex]);
            }
            minCoinCounts[value] = minCoinCount;
        }
        return minCoinCounts[amount];
    }
};
