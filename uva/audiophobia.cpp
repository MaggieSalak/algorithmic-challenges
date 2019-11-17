// 10048
 
#include <set>
#include <iostream>
#include <vector>
using namespace std;
 
const int INF = int(1e9);
 
int main() {
	// your code goes here
	int t = 0;
	int c, s, q;
	while (cin >> c >> s >> q) {
		if (c == 0 && s == 0 && q == 0) break;
		vector<vector<pair<int, int>>> v (c + 1);
		for (int i = 0; i < s; ++i) {
			int c1, c2, d; cin >> c1 >> c2 >> d;
			v[c1].push_back(make_pair(c2, d));
			v[c2].push_back(make_pair(c1, d));
		}
		cout << "Case #" << ++t << endl;
		for (int i = 0; i < q; ++i) {
			int c1, c2; cin >> c1 >> c2;
			set<pair<int, int>> pq;
			pq.insert(make_pair(0, c1));
			vector<int> dst(c + 1, INF);
			dst[c1] = 0;
			while (!pq.empty()) {
				auto nxt = *pq.begin();
				pq.erase(pq.begin());
				if (dst[nxt.second] < nxt.first) continue;
				for (auto it: v[nxt.second]) {
					int cur = max(nxt.first, it.second);
					if (cur < dst[it.first]) {
						dst[it.first] = cur;
						pq.insert(make_pair(cur, it.first));
					}
				}
			}
			int res = dst[c2];
			if (res == INF) cout << "no path" << endl;
			else cout << res << endl;
		}
		cout << endl;
	}
	return 0;
}
