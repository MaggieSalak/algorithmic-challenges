#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
		//cout << t << endl;
		int n; cin >> n;
		int p; cin >> p;
		vector<int> v;
		for (int i = 0; i < p; ++i) {
			int x; cin >> x; v.push_back(x);
		}
		int lost = 0;
		int day = 1;
		for (int d = 1; d <= n; ++d) if (d % 7 != 6 && d % 7 != 0) {
			for (auto party: v) {
				//cout << "day: " <<  d << ", party: " << party << " " << d % party << endl; 
				if (d % party == 0) {
					++lost;
					//cout << "inc lost, now: " << lost << endl;
					break;
				}
			}
			//cout << "res after day " << d << ": " << lost << endl;
		}
		cout << lost << endl;
	}
	return 0;
}
