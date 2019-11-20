#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		double res = 0;
		for (int i = 0; i < n; ++i) {
			int ar, an, env; cin >> ar >> an >> env;
			double sp = ar / (double) an;
			res += sp * env * an;
		}
		cout << round(res) << endl;
	}
	return 0;
}
