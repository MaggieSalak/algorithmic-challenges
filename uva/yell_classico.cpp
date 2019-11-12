#include <iostream>
#include <vector>
using namespace std;
 
const int NUM = 11;
 
vector<int> v;
vector<int> res;
int n;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		cin >> n;
		v.resize(n); res.resize(NUM);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			v[i] = x;
		}
		if (n < NUM) {
			cout << "Case " << k << ": go home!" << endl;
			continue;
		}
		int start = 0;
		for (int p = 0; p < NUM; ++p) {
			int pl = start;
			for (int i = start; i <= n - NUM + p; ++i) {
				if (v[i] > v[pl])
					pl = i;
			}
			res[p] = v[pl];
			start = pl + 1;
		}
		cout << "Case " << k << ":";
		for (int i = 0; i < NUM; ++i)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}
