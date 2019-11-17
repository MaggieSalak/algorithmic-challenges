#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int n;
	while (cin >> n) {
		vector<int> single(n + 1), dbl(n + 1);
		single[0] = 1;
		dbl[0] = 1;
		for (int i = 1; i <= n; ++i) {
			single[i] = dbl[i - 1];
			dbl[i] = single[i - 1] + single[i];
		}
		cout << dbl[n] << endl;
	}
	return 0;
}
