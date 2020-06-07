// Sort characters in a string by the order in which they appear in another string

#include <iostream>
#include <unordered_map>
using namespace std;
 
void sort_chars(string& s, const string& str) {
	unordered_map<char, int> m;
	for (auto c: s) m[c]++;
	int i = 0, j = 0, n1 = (int) s.size(), n2 = (int) str.size();
	while (i < n1 && j < n2) {
		for (int k = 0; k < m[str[j]]; ++k) {
			s[i] = str[j];
			++i;
		}
		m[str[j]] = 0;
		++j;
	}
	for (auto it: m) {
		for (int k = 0; k < it.second; ++k) {
			s[i] = it.first;
			++i;
		}
	}
}
 
int main() {
	// your code goes here
	string s1 = "edcccde";
	string s2 = "ce";
	sort_chars(s1, s2);
	cout << s1 << endl;
	return 0;
}
