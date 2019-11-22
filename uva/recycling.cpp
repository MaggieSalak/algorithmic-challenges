#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int main() {
	// your code goes here
	string l;
	cin >> l;
	vector<string> v;
	while (l != "#") {
		if (l[0] != 'e') {
			v.push_back(l);
		}
		else {
			vector<map<char, char>> m;
			for (const auto& l : v) {
				m.push_back(map<char, char>());
				for (int b = 0; b < 5 * 4; b += 4)
					m.back()[l[b + 2]] = l[b];
			}
			auto get_cost = [&](int p) {
				int res = 0;
				for (const auto& l : m) for (auto b: l) {
					res += b.second != m[p][b.first];
				}
				return res;
			};
			int best = get_cost(0), best_p = 0;
			for (int p = 1; p < m.size(); ++p) {
				int cur = get_cost(p);
				if (cur < best) {
					best = cur;
					best_p = p;
				}
			}
			cout << best_p + 1 << endl;
			v.clear();
		}
		cin >> l;
	}
	return 0;
}
