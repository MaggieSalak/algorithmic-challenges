#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
 
using namespace std;
 
int main() {
	// your code goes here
	unordered_map<string, vector<string>> m;
	string s;
	while (cin >> s) {
		if (s == "#") break;
		string copy = s;
		transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
		sort(copy.begin(), copy.end());
		m[copy].push_back(s);
	}
	vector<string> v;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if ((it -> second).size() == 1) v.push_back((it -> second)[0]);
	}
	sort(v.begin(), v.end());
	for (auto x: v) cout << x << endl;
	return 0;
}
