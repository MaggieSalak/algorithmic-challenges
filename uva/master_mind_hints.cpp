#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
 
pair<int, int> matches(const vector<int>& code, const vector<int>& guess, int n) {
	int strong = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; ++i)
		if (code[i] == guess[i]) 
			++strong;
		else
			m[code[i]]++;
	int weak = 0;
	for (int i = 0; i < n; ++i)
		if (code[i] != guess[i] && m.find(guess[i]) != m.end() && m[guess[i]] > 0) {
			++weak;
			m[guess[i]]--;
		}
	return make_pair(strong, weak);
}
 
int main() {
	int game = 1;
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> code;
		for (int i = 0; i < n; ++i) {
			int c;
			cin >> c;
			code.push_back(c);
		}
		cout << "Game " << game++ << ":" << endl;
		while (true) {
			vector<int> guess;
			for (int i = 0; i < n; ++i) {
				int g;
				cin >> g;
				guess.push_back(g);
			}
			if (guess[0] == 0) break;
			auto res = matches(code, guess, n);
			cout << "    (" << res.first << "," << res.second << ")" << endl;
		}
	}
	return 0;
}
