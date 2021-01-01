#include <iostream>
#include <unordered_map>
using namespace std;


string findLongest(const string& s, int max) {
	unordered_map<char, int> occur;
	int l = 0, r = 0, n = s.size();
	string res = "";
	
	while (r < n) {
		occur[s[r]]++;
		while (occur.size() > max) {
			occur[s[l]]--;
			if (occur[s[l]] == 0) {
				occur.erase(s[l]);
			}
			++l;
		}
		int newLen = r - l + 1;
		if (res.size() < newLen) {
			res = s.substr(l, newLen);
		}
		++r;
	}
	return res;
}

int main() {
	// your code goes here
	string s = "aabcccaaaac";
	cout << findLongest(s, 2) << endl;
	return 0;
}
