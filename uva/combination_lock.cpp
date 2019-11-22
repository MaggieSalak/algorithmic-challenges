#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int start, a, b, c;
	while (cin >> start >> a >> b >> c) {
		if (start == 0 && a == 0 && b == 0 && c == 0) break;
		int res = 2 * 360;
		if (start <= a) res += (start + (40 - a)) * 360 / 40;
		else res += (start - a) * 360 / 40;
		cout << "after a " << res << endl;
		res += 360;
		if (b >= a) res += (b - a) * 360 / 4;
		else res += (40 - a + b) * 360 / 4;
		cout << "after b " << res << endl;
		if (c >= b) res += (c - b) * 360 / 4;
		else res += (40 - b + c) * 360 / 4;
		cout << res << endl;
	}
	return 0;
}
