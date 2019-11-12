#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		int n, l; cin >> n >> l;
		int sm = 0;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x; v[i] = x;
			sm += x;
		}
		vector<int> w(n);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x; w[i] = x;
		}
		if (sm > l) cout << "Case " << k << ": " << "No" << endl;
		else {
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				if (v[i] > w[i]) {
					cout << "Case " << k << ": " << "No" << endl;
					ok = false;
					break;
				}
			}
			if (ok) cout << "Case " << k << ": " << "Yes" << endl;
		}
	}
	return 0;
}
