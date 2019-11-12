#include <iostream>
#include <map>
using namespace std;
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		map<char, int> mem;
		int last = 0, cur = 0, res = 0, memory = 0;
		//cout << s << endl;
		for (int cur = 0; cur < n; ++cur) {
			//cout << s[cur] << endl;
			//for (auto p: mem) cout << p.first << "->" << p.second << "; ";
			//cout << endl;
			if (mem[s[cur]] > 0)
				++res;
			if (memory == k) { 
				mem[s[last]]--;
				last++;
				--memory;
			}
			mem[s[cur]]++;
			++memory;
		}
		cout << "Case " << i << ": " << res << endl;
	}
	return 0;
}
