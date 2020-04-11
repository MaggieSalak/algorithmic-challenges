#include <iostream>
#include <vector>
using namespace std;
 
// Counts number of inversions in an array
 
int merge(vector<int>& v, int l, int mid, int r, vector<int>& m) {
	//cout << l << " " << r << " " << mid << endl;
	for (int i = l; i <= mid; ++i)
		m[i] = v[i];
	int i = l, j = mid+1, k = l;
	int res = 0;
	while (i <= mid && j <= r) {
		if (m[i] <= v[j]) {
			v[k] = m[i];
			++i;
		} else {
			res += (mid-l+1) - (i-l);
			v[k] = v[j];
			++j;
		}
		++k;
	}
	//cout << res << endl;
	while (i <= mid) {
		v[k] = m[i];
		++i;
		++k;
	}
	return res;
}
 
int mergesort(vector<int>& v, int l, int r, vector<int>& m) {
	if (l >= r) return 0;
	int mid = (l+r)/2;
	return mergesort(v, l, mid, m) + mergesort(v, mid+1, r, m) + merge(v, l, mid, r, m);
}
 
int main() {
	// your code goes here
	vector<int> v = {5, 1, 7, 4,3,2, 6};
	vector<int> m(7);
	cout << mergesort(v, 0, 6, m) << endl;
	for (auto x: v) cout << x << ", ";
	return 0;
}
