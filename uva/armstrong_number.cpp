#include <iostream>
#include <cmath>
using namespace std;
 
int digs(int n) {
	if (n == 0) return 1;
	int res = 0;
	while (n != 0) {
		++res;
		n /= 10;
	}
	return res;
}
 
bool arms(int n) {
	int k = digs(n);
	int m = n, res = 0;
	while (m != 0) {
		res += (int) pow(m%10, k);
		m /= 10;
	}
	return res == n;
}
 
int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (arms(n)) cout << "Armstrong" << endl;
		else cout << "Not Armstrong" << endl;
	}
	return 0;
}
