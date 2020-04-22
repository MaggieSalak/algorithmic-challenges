#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
 
int n;
vector<string> v;
 
bool ok(string& s) {
	map<char, int> m;
	for (auto c: s) m[c]++;
	if (m.size() < 2) return false;
	set<int> st;
	for (auto it: m)
		st.insert(it.second);
	return st.size() == m.size();
}
 
int cool() {
	int res = 0;
	for (auto s: v)
		if (ok(s)) ++res;
	return res;
}
 
int main() {
	// your code goes here
	int t = 1;
	while (cin >> n) {
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			v[i] = s;
		}
		cout << "Case " << t++ << ": " << cool() << endl;
	}
	return 0;
}
