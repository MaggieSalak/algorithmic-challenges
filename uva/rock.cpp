#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
 
bool win(char a, char b) {
	if (a == 'R') return b == 'S';
	if (a == 'S') return b == 'P';
	assert (a == 'P');
	return b == 'R';
}
 
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int q = 0; q < t; ++q) {
		int r, c, n; cin >> r >> c >> n;
		vector<string> v(r);
		for (auto& it: v) cin >> it;
		while (n--) {
			vector<string> u = v;
			for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
				for (int k =  0; k < 4; ++k) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni == r || nj < 0 || nj == c) continue;
					if (win(v[ni][nj], v[i][j])) {
						u[i][j] = v[ni][nj];
						break;
					}
				}
			}
			v = u;
		}
		for (auto& it: v) cout << it << endl;
		if (q < t - 1) cout << endl;
	}
	return 0;
}
