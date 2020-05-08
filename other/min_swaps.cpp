// Finds minimum number of swaps so that a couple can sit next to each other in a cinema

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
 
void swap(string& s, int a, int b) {
	auto c = s[a];
	s[a] = s[b];
	s[b] = c;
}
 
int swaps(string& s, int n, map<char, vector<int>>& m) {
	int i = 0, res = 0;
	while (i < n) {
		cout << s << " " << i << " " << res << endl;
		for (auto it: m) {
			cout << it.first << ": ";
			for (auto x: it.second) cout << x << " ";
			cout << endl;
		}
		if (m[s[i]].size() > 1) {
			if (s[i+1] != s[i]) {
				res++;
				int prev = m[s[i]][1]-1;
				if (m[s[prev]].size() == 1) { 
					m[s[i]][0] = prev;
					swap(s, i, prev);
					int mini = min(m[s[i]][0], m[s[i]][1]);
					int maxi = max(m[s[i]][0], m[s[i]][1]);
					m[s[i]][0] = mini; m[s[i]][1] = maxi;
					++i;
				} else {
					m[s[i+1]][0] = m[s[i]][1];
					swap(s, i+1, m[s[i]][1]);
					sort(m[s[i+1]].begin(), m[s[i+1]].end());
					i += 2;
				}
			} else
				i += 2;
		} else 
			i++;
	}
	return res;
}
 
int main() {
	// your code goes here
	map<char, vector<int>> m;
	string s; cin >> s;
	int n = (int) s.size();
	for (int i = 0; i < n; ++i)
		m[s[i]].push_back(i);
	cout << swaps(s, n, m) << endl;
	return 0;
}
