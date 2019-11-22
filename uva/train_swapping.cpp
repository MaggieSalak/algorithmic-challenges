#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int res = 0;
		int l;
		cin >> l;
		vector<bool> vis (l + 1, false);
		for (int j = 0; j < l; ++j) {
			int x;
			cin >> x;
			for (int k = x + 1; k <= l; ++k)
				if (vis[k]) 
					++res;
			vis[x] = true;
		}
		cout << "Optimal train swapping takes " << res << " swaps." << endl;
	}
	return 0;
}
