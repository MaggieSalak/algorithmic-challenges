#include <iostream>
#include <vector>
using namespace std;
 
int rows, cols;
 
int dir_r[] = { -1, 0, 1, 0 };
int dir_c[] = { 0, 1, 0, -1 };
 
bool ok(int r, int c) {
	return r >= 0 && r < rows && c >= 0 && c < cols;
}
 
bool ok_mv(const vector<string>& v, int r, int c) {
	if (!ok(r, c)) return false;
	return v[r][c] != 'T' && v[r][c] != '#'; 
}
 
bool near_trap(const vector<string>& v, int r, int c) {
	for (int i = 0; i < 4; ++i) {
		int row = r + dir_r[i], col = c + dir_c[i];
		if (ok(row, col) && v[row][col] == 'T')
			return true;
	}
	return false;
}
 
int gold(const vector<string>& v, vector<vector<bool>>& vis, int r, int c, int prev_r, int prev_c, bool back) {
	//cout << r << " " << c << endl;
	if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
	if (v[r][c] == 'T' || v[r][c] == '#') return 0;
	int res = (v[r][c] == 'G' && !back) ? 1 : 0;
	if (near_trap(v, r, c))
		return res + gold(v, vis, prev_r, prev_c, r, c, true);
	else {
		int best = 0;
		for (int i = 0; i < 4; ++i) {
			int row = r + dir_r[i], col = c + dir_c[i];
			if (ok_mv(v, row, col) && !vis[row][col]) {
				vis[row][col] = true;
				best = max(best, gold(v, vis, row, col, r, c, false));
				vis[row][col] = false;
			}
		}
		return res + best;
	}
}
 
pair<int, int> get_start(const vector<string>& v) {
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (v[i][j] == 'P')
				return make_pair(i, j);
	return make_pair(-1, -1);
}
 
int main() {
	while (cin >> cols >> rows) {
		vector<string> v;
		for (int i = 0; i < rows; ++i) {
			string s; cin >> s;
			v.push_back(s);
		}
		//for (auto s: v) cout << s << endl;
		vector<vector<bool>> vis(rows, vector<bool>(cols, false));
		auto st = get_start(v);
		vis[st.first][st.second] = true;
		v[st.first][st.second] = '.';
		cout << gold(v, vis, st.first, st.second, -1, -1, false) << endl;
	}
	return 0;
}
