#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	int n, m;
	while (cin >> n) {
		cin >> m;
		vector<int> v;
		for (int i = 0; i < m; ++i) {
			int x; cin >> x;
			v.push_back(x);
		}
		vector<int> winners(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			for (auto mv: v) if (mv <= i) {
				if (winners[i - mv] == 0) {
					winners[i] = 1;
					break;
				}
			}
		}
		if (winners[n]) cout << "Stan"; else cout << "Ollie";
		cout << " wins" << endl;
	}
	return 0;
}
