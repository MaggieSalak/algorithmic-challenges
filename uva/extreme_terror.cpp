#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int c = 1; c <= t; ++c) {
		int n, k; cin >> n >> k;
		vector<int> give(n), get(n);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			give[i] = x;
		}
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			get[i] = x;
		}
		vector<int> prof(n);
		for (int i = 0; i < n; ++i) {
			prof[i] = get[i] - give[i];
		}
		sort(prof.begin(), prof.end());
		int res = 0, reject = 0;
		for (int i = 0; i < n; ++i) {
			if (prof[i] < 0 && reject < k)
				++reject;
			else res += prof[i];
		}
		cout << "Case " << c << ": ";
		if (res <= 0) cout << "No Profit" << endl;
		else cout << res << endl;
	}
	return 0;
}
