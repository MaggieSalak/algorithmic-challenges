class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (const auto& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(s);
        }
        
        vector<vector<string>> res;
        for (const auto& p : m) {
            res.push_back(p.second);
        }
        
        return res;
    }
};
