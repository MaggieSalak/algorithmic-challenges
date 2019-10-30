#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
int n;
vector<pair<int, int>> v;
 
double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
 
bool isosceles(int i, int j, int k) {
	auto d1 = dist(v[i].first, v[i].second, v[j].first, v[j].second);
	auto d2 = dist(v[j].first, v[j].second, v[k].first, v[k].second);
	auto d3 = dist(v[i].first, v[i].second, v[k].first, v[k].second);
	if (abs(d1 + d2 - d3) < pow(10,-6)) return false;
	if (abs(d1 + d3 - d2) < pow(10,-6)) return false;
	if (abs(d2 + d3 - d1) < pow(10,-6)) return false;
	if (abs(d1-d2) < pow(10,-6)) return true;
	if (abs(d2-d3) < pow(10,-6)) return true;
	if (abs(d1-d3) < pow(10,-6)) return true;
	return false;
}
 
int count(int cur, int taken, vector<int>& v) {
	if (taken == 3)
		if (isosceles(v[0], v[1], v[2])) {
			//cout << v[0] << "," << v[1] << "," << v[2] << endl; 			
			return 1;
		}
		else return 0;
	else if (cur >= n) return 0;
	v[taken] = cur;
	int res = count(cur+1, taken+1, v);
	v[taken] = -1;
	res += count (cur+1, taken, v);
	return res;
}
 
int main() {
	// your code goes here
	while (cin >> n) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			v.emplace_back(x, y);
		}
		vector<int> w(3, -1);
		cout << count(0, 0, w) << endl;
	}
	return 0;
}
