#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int dir_f[] = {0, 0, 0, 0, 1, -1};
int dir_r[] = {0, 1, 0, -1, 0, 0};
int dir_c[] = {1, 0, -1, 0, 0, 0};
 
vector<vector<vector<char>>> v;
vector<vector<vector<bool>>> vis;
int rows, cols, fls, stf, str, stc, enf, enr, enc;
 
struct cell {
	int f; int r; int c;
	cell(int fl, int ro, int co) : f(fl), r(ro), c(co) {}
};
 
bool ok(int f, int r, int c) {
	return 0 <= f && f < fls && 0 <= r && r < rows && 0 <= c && c < cols && v[f][r][c] != '#';
}
 
int shortest() {
	queue<pair<cell, int>> q;
	cell c(stf, str, stc);
	q.push(make_pair(c, 0));
	vis[stf][str][stc] = true;
	while (!q.empty()) {
		auto fr = q.front(); q.pop();
		cell cl = fr.first;
		//cout << cl.f << " " << cl.r << " " << cl.c << endl;
		if (cl.f == enf && cl.r == enr && cl.c == enc) return fr.second;
		for (int i = 0; i < 6; ++i) {
			int f1 = cl.f+dir_f[i], r1 = cl.r+dir_r[i], c1 = cl.c+dir_c[i];
			if (ok(f1, r1, c1) && !vis[f1][r1][c1]) {
				if (i == 4 && (cl.f == fls-1 || v[cl.f][cl.r][cl.c] != '-' || v[f1][r1][c1] != '-')) continue;
				if (i == 5 && (cl.f == 0 || v[cl.f][cl.r][cl.c] != '-' || v[f1][r1][c1] != '-')) continue;
				vis[f1][r1][c1] = true;
				cell cl1(f1, r1, c1);
				q.push(make_pair(cl1, fr.second+1));
			}
		}
	}
	return -1;
}
 
int main() {
	// your code goes here
	while (cin >> rows >> cols >> fls) {
		if (rows == 0) break;
		v.clear();
		v.resize(fls, vector<vector<char>>(rows, vector<char>(cols)));
		vis.clear();
		vis.resize(fls, vector<vector<bool>>(rows, vector<bool>(cols, false)));
		for (int i = 0; i < fls; ++i) {
			for (int j = 0; j < rows; ++j) {
				for (int k = 0; k < cols; ++k) {
					char c; cin >> c;
					v[i][j][k] = c;
					if (c == 'S') { stf = i; str = j; stc = k; }
					if (c == 'E') { enf = i; enr = j; enc = k; }
				}
			}
		}
		cout << shortest() << endl;
	}
	return 0;
}
