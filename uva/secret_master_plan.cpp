#include <iostream>
#include <vector>
using namespace std;
 
int x[] = {0, 0, 1, 1};
int y[] = {0, 1, 1, 0};
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		vector<vector<int>> v1(2, vector<int>(2)), v2(2, vector<int>(2));
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				int x; cin >> x;
				v1[i][j] = x;
			}
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				int x; cin >> x;
				v2[i][j] = x;
			}
		bool ok;
		for (int i = 0; i < 4; ++i) {
			int x1 = 0, y1 = 0, x2 = x[i], y2 = y[i];
			ok = true;
			for (int j = 0; j < 4; ++j) {
				if (v1[x1][y1] != v2[x2][y2]) ok = false;
				x1 = x[j+1], y1 = y[j+1];
				x2 = x[(i+j+1)%4], y2 = y[(i+j+1)%4];
			}
			if (ok) break;
		}
		cout << "Case #" << k << ": ";
		if (ok) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
