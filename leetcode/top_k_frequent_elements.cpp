class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToCount;
        map<int, unordered_set<int>> countToNums;
        
        for (const auto& n : nums) {
            int count = ++numToCount[n];
            countToNums[count].insert(n);
            if (count > 1) {
                countToNums[count-1].erase(n);
            }
        }
        
        vector<int> res;
        auto it = countToNums.rbegin();
        
        while (res.size() < k) {
            for (const auto& n : it->second) {
                if (res.size() < k) {
                    res.push_back(n);
                }
            }
            ++it;
        }
        
        return res;
    }
};
