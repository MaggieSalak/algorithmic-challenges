// Given a 2D board with 0s and 1s, finds the distance to the closest 1 for each 0

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
const int MAX_DIST = 9999999;
 
bool ok(int x, int y, int rows, int cols) {
	return 0 <= x && x < rows && 0 <= y && y < cols;
}
 
void push_ones(const vector<vector<bool>>& v, vector<vector<bool>>& visited, vector<vector<int>>& res, int rows, int cols, queue<pair<int, int>>& q) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			if (v[r][c]) {
				visited[r][c] = true;
				res[r][c] = 0;
				q.push(make_pair(r, c));
			}
		}
	}
}
 
void closest(const vector<vector<bool>>& v, vector<vector<bool>>& visited, vector<vector<int>>& res, int rows, int cols) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> shifts = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
	push_ones(v, visited, res, rows, cols, q);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto s : shifts) {
			auto r = make_pair(p.first + s.first, p.second + s.second);
			if (ok(r.first, r.second, rows, cols) && !visited[r.first][r.second]) {
				visited[r.first][r.second] = true;
				res[r.first][r.second] = res[p.first][p.second] + 1;
				q.push(r);
			}
		}
	}
}
 
vector<vector<int>> closest_ones(const vector<vector<bool>>& v) {
	int rows = (int) v.size();
	int cols = (int) v[0].size();
	vector<vector<int>> res (rows, vector<int> (cols, MAX_DIST));
	vector<vector<bool>> visited (rows, vector<bool> (cols, false));
	closest(v, visited, res, rows, cols);
	return res;
}
 
 
int main() {
	// your code goes here
	vector<vector<bool>> v (4);
	v[0] = {false, false, false, false};
	v[1] = {false, false, true, false};
	v[2] = {true, false, false, false};
	v[3] = {false, false, false, true};
	vector<vector<int>> res = closest_ones(v);
	for (auto row : res) {
		for (auto x : row)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}
