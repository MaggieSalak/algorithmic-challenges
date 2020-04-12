#include <iostream>
#include <vector>
using namespace std;

// Split array into 2 subarrays with equal sum

void equal(const vector<int>& v) {
	auto n = (int) v.size();
	vector<int> pref (n);
	pref[0] = v[0];
	for (int i = 1; i < n; ++i)
		pref[i] = pref[i-1] + v[i];
	for (int i = 0; i < n; ++i) {
		int lsum = i == 0 ? 0 : pref[i-1];
		int rsum = pref[n-1] - pref[i];
		if (lsum == rsum) cout << i << endl;
	}
}
 
int main() {
	// your code goes here
	vector<int> v = {-1, 3, -4, 5, 1, -6, 2, 1};
	equal(v);
	return 0;
}
