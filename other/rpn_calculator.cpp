#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
 
struct Item {
	bool num;
	string op;
	int value;
};
 
bool is_op(string s) {
	return s == "+" || s == "*";
}
 
int calc(Item i, Item j, Item oper) {
	if (oper.op == "+") return i.value + j.value;
	return i.value * j.value;
}
 
int calc(const vector<string>& v) {
	stack<Item> st;
 	for (string s : v) {
 		Item i;
 		if (is_op(s)) {
 			i.num = false;
 			i.op = s;
 			st.push(i);
 			continue;
 		}
 		i.num = true;
 		i.value = stoi(s);
 		while (!st.empty() && st.top().num) {
 			Item j = st.top();
 			st.pop();
 			Item oper = st.top();
 			st.pop();
 			i.value = calc(i, j, oper);
 		}
 		st.push(i);
 	}
 	return st.top().value;
}
 
int calc(string e) {
	stringstream ss = stringstream(e);
	vector<string> v;
	string s;
	while (ss >> s)
		v.push_back(s);
	return calc(v);
}
 
int main() {
	// your code goes here
	cout << calc("+ 2 * 3 * 2 4") << endl;
	return 0;
}
