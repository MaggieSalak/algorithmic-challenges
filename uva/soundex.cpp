#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main() {
 
	map<char, int> m;
m['B'] = 1;
m['F'] = 1;
m['P'] = 1;
m['V'] = 1;
m['C'] = 2;
m['G'] = 2;
m['J'] = 2;
m['K'] = 2;
m['Q'] = 2;
m['S'] = 2;
m['X'] = 2;
m['Z'] = 2;
m['D'] = 3;
m['T'] = 3;
m['L'] = 4;
m['M'] = 5;
m['N'] = 5;
m['R'] = 6;
 
	// your code goes here
	string s;
	while (cin >> s) {
		vector<int> v;
		int n = (int) s.size();
		for (int i = 0; i < n; ++i)
			if (m.find(s[i]) != m.end())
				if (i == 0 || m.find(s[i-1]) == m.end() || m[s[i-1]] != m[s[i]])
					v.push_back(m[s[i]]);
		for (auto x: v)
			cout << x;
		cout << endl;
	}
	return 0;
}
