#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		int l, r, s;
		cin >> l >> r >> s;
		vector<unordered_set<int>> v(3);
		for (int i = 0; i < l; ++i) {
			int x; cin >> x;
			v[0].insert(x);
		}
		for (int i = 0; i < r; ++i) {
			int x; cin >> x;
			v[1].insert(x);
		}
		for (int i = 0; i < s; ++i) {
			int x; cin >> x;
			v[2].insert(x);
		}
		cout << "Case #" << k << ":" << endl;
		for (int i = 0; i < 3; ++i) {
			int minus = 0;
			int j = (i+1)%3, k = (i+2)%3;
			for (auto x: v[i])
				if (v[j].count(x) > 0 || v[k].count(x) > 0) ++minus;
			cout << v[i].size() - minus << " ";
 
			int others = 0;
			for (auto x: v[j])
				if (v[k].count(x) > 0 && v[i].count(x) == 0)
					++others;
			cout << others << endl;
		}
	}
	return 0;
}
