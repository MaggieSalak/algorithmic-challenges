#include <iostream>
using namespace std;
 
bool digit(char c) { return '0' <= c && c <= '9'; }
 
int parse_int(string& s, int& index) {
	int res = 0;
	while (index < s.size() && digit(s[index])) {
		res *= 10;
		res += s[index] - '0';
		index++;
	}
	return res;
}
 
int main() {
	// your code goes here
	int t; cin >> t;
	for (int k = 1; k <= t; ++k) {
		string s; cin >> s;
		string res = "";
		int index = 0;
		while (index < s.size()) {
			char c = s[index];
			++index;
			int n = parse_int(s, index);
			//cout << c << " " << n << endl;
			for (int i = 1; i <= n; ++i)
				res += c;
		}
		cout << "Case " << k << ": " << res << endl;
	}
	return 0;
}
