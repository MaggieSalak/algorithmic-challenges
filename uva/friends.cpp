#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int dfs(int cur, map<int, vector<int>>& m, vector<bool>& visited) {
	visited[cur] = true;
	int res = 1;
	for (auto neigh: m[cur]) {
		if (!visited[neigh]) {
			res += dfs(neigh, m, visited);
		}
	}
	return res;
}
 
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		map<int, vector<int>> mp;
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		int res = 0;
		vector<bool> visited(n+1, false);
		for (int i = 1; i <= n; ++i)
			if (!visited[i])
				res = max(res, dfs(i, mp, visited));
		cout << res << endl;
	}
	return 0;
}
