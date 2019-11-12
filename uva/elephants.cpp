#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			v[i] = x;
		}
		sort(v.begin(), v.end());
		int sm = 0, res = 0, i = 0;
		while (i < n && sm < w) {
			if (sm + v[i] <= w) {
				sm += v[i];
				++res;
			}
			++i;
		}
		cout << res << endl;
 	}
	return 0;
}
