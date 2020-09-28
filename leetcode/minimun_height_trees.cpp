class Solution {
public:
    unordered_map<int, unordered_set<int>> restructure(int n, const vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> edgeMap;
        for (int i = 0; i < n-1; ++i) {
            auto edge = edges[i];
            edgeMap[edge[0]].insert(edge[1]);
            edgeMap[edge[1]].insert(edge[0]);
        }
        return edgeMap;
    }
    
    void dfs(int cur, unordered_map<int, unordered_set<int>>& edgeMap, vector<bool>& vis, int height, int& maxHeight) {
        vis[cur] = true;
        maxHeight = max(maxHeight, height);
        for (int neigh : edgeMap[cur]) {
            if (!vis[neigh]) {
                dfs(neigh, edgeMap, vis, height+1, maxHeight);
            }
        }
    }
    
    int getHeight(int i, int n, unordered_map<int, unordered_set<int>>& edgeMap) {
        int maxHeight = 0;
        vector<bool> vis(n, false);
        dfs(i, edgeMap, vis, 0, maxHeight);
        return maxHeight;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        auto edgeMap = restructure(n, edges);
        
        unordered_map<int, int> heights;
        
        int minH = -1;
        for (int i = 0; i < n; ++i) {
            int height = getHeight(i, n, edgeMap);
            heights[i] = height;
            if (minH == -1 || height < minH) {
                minH = height;
            }
        }
        
        vector<int> res;
        
        for (const auto& p : heights) {
            if (p.second == minH) {
                res.push_back(p.first);
            }
        }
        
        return res;
    }
};
