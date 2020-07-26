class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countPerVal;
        map<int, unordered_set<int>> valuesPerCount;
        
        for (const auto& n : nums) {
            int count = countPerVal[n];
            
            if (valuesPerCount.find(count) != valuesPerCount.end())
                valuesPerCount[count].erase(n);
            
            valuesPerCount[count+1].insert(n);
            countPerVal[n]++;
            
        }
        vector<int> res;
        auto it = valuesPerCount.rbegin();
        int taken = 0;
        while (taken < k) {
            cout << it->first << endl;
            auto s = it->second;
            for (auto it1 = s.begin(); it1 != s.end(); ++it1) {
                 if (taken == k) 
                    break;
                 res.push_back(*it1);
                 ++taken;
           }
           ++it;
        }
        return res;
    }
};
