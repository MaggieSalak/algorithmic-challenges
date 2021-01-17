#include <iostream>
#include <vector>
using namespace std;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void mark_island(const vector<vector<bool>>& v, vector<vector<bool>>& vis, 
			int i, int j, int m, int n) {
	vis[i][j] = true;
	for (int k = 0; k < 4; ++k) {
		int i1 = i+di[k];
		int j1 = j+dj[k];
		if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n) {
			if (!vis[i1][j1] && v[i1][j1]) {
				mark_island(v, vis, i1, j1, m, n);
			}
		}
	}
	
}

int count_islands(const vector<vector<bool>>& v, int m, int n) {
	vector<vector<bool>> vis(m, vector<bool>(n, false));
	int islands = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] && !vis[i][j]) {
				++islands;
				mark_island(v, vis, i, j, m, n);
			}
		}
	}
	return islands;
}

int main() {
	// your code goes here
	vector<vector<bool>> v;
	vector<bool> w1 = {false, true, true, true, false};
	vector<bool> w2 = {false, true, false, false, true};
	vector<bool> w3 = {false, true, false, true, false};
	vector<bool> w4 = {true, true, true, false, true};
	vector<bool> w5 = {false, true, false, false, true};
	v.push_back(w1);
	v.push_back(w2);
	v.push_back(w3);
	v.push_back(w4);
	v.push_back(w5);
	cout << count_islands(v, 5, 5) << endl;
	return 0;
}
