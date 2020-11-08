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
