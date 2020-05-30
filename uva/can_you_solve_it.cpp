#include <iostream>
using namespace std;
 
int from_orig(int x, int y) {
	int sm = x + y;
	return (sm * (sm + 1)) / 2 + x;
}
 
int main() {
	// your code goes here
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int steps = 0;
		cout << "Case " << i << ": " << from_orig(x2, y2) - from_orig(x1, y1) << endl;
	}
	return 0;
}
