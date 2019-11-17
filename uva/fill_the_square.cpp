#include <iostream>
#include <vector>
using namespace std;
 
int dir_r[] = { -1, 0, 1, 0 };
int dir_c[] = { 0, 1, 0, -1 };
 
bool cell_ok(int r, int c, int n) {
	return 0 <= r && r < n && 0 <= c && c < n;
}
 
bool char_ok(const vector<string>& v, char c, int r, int col, int n) {
	for (int i = 0; i < 4; ++i) {
		int r2 = r + dir_r[i];
		int c2 = col + dir_c[i];
		if (cell_ok(r2, c2, n) && v[r2][c2] == c)
			return false;
	}
	return true;
}
 
char get_char(const vector<string>& v, int r, int col, int n) {
	char c = 'A';
	while (true) {
		if (char_ok(v, c, r, col, n))
			return c;
		c = char(int(c) + 1);
	}
}
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		int n; cin >> n;
		vector<string> v;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			v.push_back(s);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (v[i][j] == '.')
					v[i][j] = get_char(v, i, j, n);
		cout << "Case " << k << ":" << endl;
		for (auto w: v)
			cout << w << endl;
	}
	return 0;
}
