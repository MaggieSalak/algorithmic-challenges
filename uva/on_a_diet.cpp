#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int q = 0; q < t; ++q) {
		int n, p; cin >> n >> p;
		vector<int> v(p);
		for (auto& a : v) cin >> a;
		int sum = 0;
		for (auto a : v) sum += a;
		if (sum < n) cout << "NO SOLUTION\n";
		else {
			vector<int> dp(sum + 1, 0);
			dp[0] = 1;
			for (auto a : v)
				for (int i = sum; i >= 0; --i)
					if (dp[i] && i + a <= sum)
						dp[i+a] = 1;
			int res = -1;
			for (int i = n; i <= sum; ++i)
				if (dp[i]) {
					res = i;
					break;
				}
			assert(res != -1);
			cout << res << endl;
		}
	}
	return 0;
}

