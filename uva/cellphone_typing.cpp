#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
 
struct trie {
	int cnt;
	map<char, trie*> m;
};
 
void print_debug(trie *t) {
	cout << t->cnt << endl;
	for (auto it: t->m) {
		cout << it.first << endl;
		print_debug(it.second);
	}
}
 
trie* create_empty() {
	trie *t = new trie(), *s = new trie ();
	t->cnt = 1;
	s->cnt = 1;
	t->m['$'] = s;
	return t;
}
 
void augment(trie* t, string s) {
	s += '$';
	for (auto c : s) {
		t->cnt++;
		if (t->m[c] == NULL) {
			t->m[c] = new trie();
			t = t->m[c];
			t->cnt = 0;
		}
		else t = t->m[c];
	}
}
 
int walk(trie *t) {
	int res = 0;
	if (t->m.size() > 1) {
		res = t->cnt;
		if (t->m['$'] != NULL)
			res--;
	}
	for (auto it: t->m)
		if (it.first != '$')
			res += walk(it.second);
	return res;
}
 
int main() {
	// your code goes here
	int n;
	while (cin >> n) {
		vector<string> v(n);
		for (auto& it: v) cin >> it;
		trie *t = create_empty();
		for (auto& it: v)
			augment(t, it);
		//print_debug(t);
		cout << setprecision(2) << fixed << walk(t) / double(n) << endl;
	}
	return 0;
}
