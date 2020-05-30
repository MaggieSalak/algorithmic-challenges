#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
	// your code goes here
	ll n, m;
	while (cin >> n >> m) {
		if (n == 0) break;
		ll res = n * m * (m - 1) + m * n * (n - 1);
		ll diag = 0;
		for (ll i = 2; i < min(n, m); ++i)
			diag += 4 * i * (i - 1);
		for (ll i = 1; i <= max(n, m) - min(n, m) + 1; ++i)
			diag += 2 * min(n, m) * (min(n, m) - 1);
		res += diag;
		cout << res << endl;
	}
	return 0;
}
