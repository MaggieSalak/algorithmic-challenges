#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
 
int balls(int n) {
	vector<int> v (n, 0);
	int cur = 1;
	while (true) {
		cout << cur << endl;
		//for (auto p: v) cout << p << ", ";
		//cout << endl;
		int peg = 0;
		while (peg < n) {
			auto root = sqrt(v[peg] + cur);
			cout << peg << " " << v[peg] << " " << root << endl;
			if (v[peg] == 0 || root * root == v[peg] + cur) {
				v[peg] = cur;
				break;
			}  
			++peg;
		}
		cout << peg << " " << n << endl;
		if (peg == n) return cur - 1;
		++cur;
	}
	return -1;
}
 
int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << balls(n) << endl;
	}
	return 0;
}
