struct Profit {
    int bought;
    int sold;
    int cooldown_nostock;
    int cooldown_stock;
};

class Solution {
public:
    int getMaxProfit(Profit p) {
        int m = max(p.bought, p.sold);
        m = max(m, p.cooldown_stock);
        m = max(m, p.cooldown_nostock);
        return m;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
          
        vector<Profit> profits;
        Profit p0;
        p0.bought = -prices[0];
        p0.sold = INT_MIN;
        p0.cooldown_stock = INT_MIN;
        p0.cooldown_nostock = 0;
        profits.push_back(p0);
        
        for (int i = 1; i < n; ++i) {
            Profit p1 = profits[i-1];
            
            Profit p;
            p.bought = max(p1.cooldown_nostock - prices[i], p1.bought);
            p.sold = max(p1.cooldown_stock + prices[i], p1.bought + prices[i]);
            p.cooldown_stock = max(p1.cooldown_stock, p1.bought);
            p.cooldown_nostock = max(p1.cooldown_nostock, p1.sold);
            
            profits.push_back(p);
        }
        Profit finalProfit = profits[n-1];
        return getMaxProfit(finalProfit);
    }
};
