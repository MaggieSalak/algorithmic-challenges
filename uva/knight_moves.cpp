#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int dir_r[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dir_c[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 
bool ok(int r, int c) {
	return 0 <= r && r < 8 && 0 <= c && c < 8;
}
 
void moves(int r1, int c1, vector<vector<int>>& vis) {
	queue<pair<int, int>> q;
	vis[r1][c1] = 0;
	q.push(make_pair(r1, c1));
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			int r = p.first + dir_r[i], c = p.second + dir_c[i];
			if (ok(r, c) && vis[r][c] == -1) {
				vis[r][c] = vis[p.first][p.second] + 1;
				q.push(make_pair(r, c));
			}
		}
	}
}
 
int main() {
	// your code goes here
	string f1, f2;
	while (cin >> f1 >> f2) {
		int r1 = f1[1] - '1';
		int c1 = f1[0] - 'a';
		int r2 = f2[1] - '1';
		int c2 = f2[0] - 'a';
		//cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
		vector<vector<int>> vis(8, vector<int>(8, -1));
		moves(r1, c1, vis);
		cout << "To get from " << f1 << " to " << f2 << " takes " << vis[r2][c2] << " knight moves." << endl;
	}
	return 0;
}
