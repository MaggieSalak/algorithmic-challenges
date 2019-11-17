#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
 
int main() {
	// your code goes here
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		int x;
		vector<int> v;
		set<int> s;
		while (ss >> x) {
			v.push_back(x);
			s.insert(x);
		}
		cout << line << endl;
		reverse(v.begin(), v.end());
		int to_pos = 0;
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			int val = *it;
			int pos;
			for (int i = 0; i < v.size(); ++i)
				if (v[i] == val) pos = i;
			cout << pos + 1 << " ";
			reverse(v.begin() + pos, v.end());
			reverse(v.begin() + to_pos, v.end());
			cout << ++to_pos << " ";		
		}
		cout << 0 << endl;
	}
	return 0;
}
