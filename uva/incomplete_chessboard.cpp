#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
const int SIZE = 8;
 
struct Cell {
	int x; 
	int y;
};
 
int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[] = {0, 1, 1, 1, 0, -1, -1, -1};
 
bool ok(int x1, int y1, int x2, int y2) {
	if (x1 < 1 || x1 > SIZE || y1 < 1 || y1 > SIZE)
		return false;
	return x1 != x2 || y1 != y2;
}
 
int dist(int x1, int y1, int x2, int y2, int x3, int y3, vector<vector<bool>>& vis) {
	queue<pair<Cell, int>> q;
	Cell c; c.x = x1; c.y = y1;
	q.push(make_pair(c, 0));
	vis[x1][y1] = true;
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		Cell cl = p.first; int dst = p.second;
		//cout << cl.x << "," << cl.y << " " << dst << endl;
		if (cl.x == x2 && cl.y == y2) return dst;
		for (int i = 0; i < SIZE; ++i) {
			int r = cl.x + row[i], c = cl.y + col[i];
			if (ok(r, c, x3, y3) && !vis[r][c]) {
				Cell neigh; neigh.x = r; neigh.y = c;
				q.push(make_pair(neigh, dst+1));
				vis[r][c] = true;
			}
		}
	}
	return -1;
}
 
int main() {
	// your code goes here
	int x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		vector<vector<bool>> vis(SIZE+1, vector<bool>(SIZE+1, false));
		cout << dist(x1, y1, x2, y2, x3, y3, vis) << endl;
	}
	return 0;
}
