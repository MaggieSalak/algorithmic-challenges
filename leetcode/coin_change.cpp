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

// 2: With dynamic programming, complexity O(Amount * CoinCount^2)

class Solution {
public:
    int getMin(const vector<int>& v) {
        int res = -1;
        for (auto val : v) {
            if (res == -1) {
                res = val;
            } else if (val != -1) {
                res = min(res, val);
            }
        }
        return res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        int coinCount = coins.size();
        vector<vector<int>> val(amount+1, vector<int>(coinCount, -1));
        
        for (int value = 1; value <= amount; ++value) {
            for (int coinIndex = 0; coinIndex < coinCount; ++coinIndex) {
                int coin = coins[coinIndex];
                if (value - coin == 0) {
                    val[value][coinIndex] = 1;
                } else if (value - coin > 0) {
                    int mn = getMin(val[value - coin]);
                    if (mn == -1) {
                        val[value][coinIndex] = -1;
                    } else {
                        val[value][coinIndex] = mn + 1;
                    }
                }
                
            }
        }
        
        return getMin(val[amount]);
    }
};
