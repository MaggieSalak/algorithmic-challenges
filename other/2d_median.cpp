// Find median in a 2d array with n sorted rows and m columns

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
double median(const vector<vector<int>>& v, int n, int m) {
	priority_queue<int, vector<int>, greater<int>> min_pq;
	int elem = (n*m)/2 + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			min_pq.push(v[i][j]);
			if (min_pq.size() > elem)
				min_pq.pop();
		}
	}
	if ((n*m)%2 == 1) return (double) min_pq.top();
	else {
		auto a = min_pq.top(); min_pq.pop();
		auto b = min_pq.top();
		return (a+b)/(double) 2;
	}
}
 
int main() {
	// your code goes here
	vector<vector<int>> v;
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2 = {2, 3, 3, 4, 5};
	//vector<int> v3 = {1, 3, 6, 7, 8};
	v.push_back(v1); v.push_back(v2);// v.push_back(v3);
	cout << median(v, 2, 5) << endl;
	return 0;
}
