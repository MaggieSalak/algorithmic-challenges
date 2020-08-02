 bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> usedChars;
        
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                if (usedChars.count(t[i]) > 0)
                    return false;
                m[s[i]] = t[i];
                usedChars.insert(t[i]);
            }
                
            else if (m[s[i]] != t[i]) 
                return false;
        }
        return true;
    }
