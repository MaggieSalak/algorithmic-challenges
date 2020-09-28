class Solution {
public:
    
    int divisors(int n) {
        int res = 0;
        int div = 1;        
        while (div <= sqrt(n)) {
            if (n % div == 0) {  
                if (n / div == div) { 
                    res += 1;
                } else {
                    res += 2;
                }
            }
            ++div;
        }
        return res;
    }
    
    int bulbSwitch(int n) {
        int res = 0;
        
        for (int i = 1; i <= n; ++i) {
            int div = divisors(i);
            res += div % 2;
        }
        
        return res;
    }
};
