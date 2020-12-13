class Solution {
public:
    struct TreeVal {
        TreeVal() : val(0), isNull(true) {}
        TreeVal(int a) : val(a), isNull(false) {}
        int val;
        bool isNull;
    };
    
    int strToInt(const string& str) {
        int res = 0;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            res *= 10;
            res += str[i] - '0';
        }
        return res;
    }
    
    vector<TreeVal> parse(const string& str) {
        vector<TreeVal> res;
        int i = 0, n = str.size();
        while (i < n) {
            int j;
            auto pos = str.find(',', i);
            if (pos != string::npos) {
                j = pos; 
            } else {
                j = n;
            }
            string sub = str.substr(i, j-i);
            TreeVal tv;
            if (sub != "#") {
                tv.isNull = false;
                tv.val = strToInt(sub);
            }
            res.push_back(tv);
            i = j + 1;
        }
        return res;
    }
    
    bool pushNull(stack<TreeVal>& s) {
        while (!s.empty() && s.top().isNull) {
            s.pop();
            if (s.empty()) {
                return false;        
            }
            s.pop();
        }
        TreeVal tv;
        tv.isNull = true;
        s.push(tv);
        return true;
    }
    
    bool isValidSerialization(string preorder) {
        vector<TreeVal> v = parse(preorder);
        int n = v.size();
        stack<TreeVal> s;
        
        for (auto tv : v) {
            if (tv.isNull) {
                if (!pushNull(s))
                    return false;
            } else {
                s.push(tv);
            }
        }
        if (s.size() != 1) {
            return false;
        }
        if (!s.top().isNull) {
            return false;
        }
        return true;
        
    }
};
