#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
struct card {
	int val;
	char suit;
};
 
vector<card> v;
map<string, int> ranks;
map<int, string> names;
map<int, char> values;
 
bool myfunction(card c1, card c2) { return (c1.val < c2.val); }
 
card convert(const string& s) {
	card cd;
	char c = s[0];
	if ('2' <= c && c <= '9') cd.val = c - '0';
	if (c == 'T') cd.val = 10;
	if (c == 'J') cd.val = 11;
	if (c == 'Q') cd.val = 12;
	if (c == 'K') cd.val = 13;
	if (c == 'A') cd.val = 14;
	cd.suit = s[1];
	//cout << s << " " << c << " converted to: " << cd.val << " " << cd.suit << endl; 
	return cd;
}
 
map<int, int> of_a_kind(vector<card>& v) {
	map<int, int> res;
	for (int i = 0; i < 5; ++i)
		res[v[i].val]++;
	return res;
}
 
bool is_flush(const vector<card>& v) {
	for (int i = 1; i < 5; ++i)
		if (v[i].suit != v[i-1].suit)
			return false;
	return true;
}
 
bool is_straight(const vector<card>& v) {
	//for (auto c: v) cout << c.val << c.suit << " ";
	//cout << endl;
	vector<card> w = v;
	sort(w.begin(), w.end(), myfunction);
	bool ok = true;
	for (int i = 1; i < 5; ++i)
		if (w[i].val != w[i-1].val+1)
			ok = false;
	if (ok) {
		//cout << " OK" << endl;
		return true;
	}
	return (w[0].val == 2 && w[1].val == 3 && w[2].val == 4 && w[3].val == 5 && w[4].val == 14);
}
 
bool has_four(map<int, int>& m) {
	for (auto it: m)
		if (it.second == 4)
			return true;
	return false;
}
 
bool has_three(map<int, int>& m) {
	for (auto it: m)
		if (it.second == 3)
			return true;
	return false;
}
 
bool has_pair(map<int, int>& m) {
	for (auto it: m)
		if (it.second == 2)
			return true;
	return false;
}
 
bool is_full(map<int, int>& m) {
	bool three = false, two = false; 
	for (auto it: m) {
		if (it.second >= 3 && !three) three = true;
		else if (it.second >= 2) two = true;
	}
	return two && three;
}
 
bool has_two_pairs(map<int, int>& m) {
	bool one = false, two = false;
	for (auto it: m) {
		if (it.second >= 2 && !one) one = true;
		else if (it.second >= 2) two = true;
	}
	return one && two;
}
 
 
void combinations(const vector<card>& v, vector<card>& cards, int elem, int cur, int& res) {
	if (elem == 5) {
		auto mp = of_a_kind(cards);
		if (is_straight(cards) && is_flush(cards)) res = ranks["straight-flush"];
		else if (has_four(mp)) res = max(res, ranks["four-of-a-kind"]);
		else if (is_full(mp)) res = max(res, ranks["full-house"]);
		else if (is_flush(cards)) res = max(res, ranks["flush"]);
		else if (is_straight(cards)) res = max(res, ranks["straight"]);
		else if (has_three(mp)) res = max(res, ranks["three-of-a-kind"]);
		else if (has_two_pairs(mp)) res = max(res, ranks["two-pairs"]);
		else if (has_pair(mp)) res = max(res, ranks["one-pair"]);
	} else if (cur < 10) {
		cards.push_back(v[cur]);
		combinations(v, cards, elem+1, cur+1, res);
		cards.pop_back();
		if (cur < 5)
			combinations(v, cards, elem, cur+1, res);
	}
}
 
int main() {
	// your code goes here
	ranks["highest-card"] = 1; ranks["one-pair"] = 2; ranks["two-pairs"] = 3; ranks["three-of-a-kind"] = 4;
	ranks["straight"] = 5; ranks["flush"] = 6; ranks["full-house"] = 7; ranks["four-of-a-kind"] = 8;
	ranks["straight-flush"] = 9;
 
	names[1] = "highest-card"; names[2] = "one-pair"; names[3] = "two-pairs"; names[4] = "three-of-a-kind";
	names[5] = "straight"; names[6] = "flush"; names[7] = "full-house"; names[8] = "four-of-a-kind";
	names[9] = "straight-flush";
 
	values[2] = '2'; values[3] = '3'; values[4] = '4'; values[5] = '5'; values[6] = '6'; values[7] = '7';
	values[8] = '8'; values[9] = '9'; values[10] = 'T'; values[11] = 'J'; values[12] = 'Q';
	values[13] = 'K'; values[14] = 'A';
 
	string s;
	while (cin >> s) {
		v.clear();
		card cd = convert(s);
		v.push_back(cd);
		for (int i = 1; i < 10; ++i) {
			cin >> s;
			cd = convert(s);
			v.push_back(cd);
		}
		vector<card> w = v;
		vector<card> cards;
		int res = ranks["highest-card"];
		combinations(v, cards, 0, 0, res);
		cout << "Hand: ";
		for (int i = 0; i < 5; ++i)
			cout << values[w[i].val] << w[i].suit << " ";
		cout << "Deck: ";
		for (int i = 5; i < 10; ++i)
			cout << values[w[i].val] << w[i].suit << " ";
		cout << "Best hand: " << names[res] << endl; 
	}
	return 0;
}
