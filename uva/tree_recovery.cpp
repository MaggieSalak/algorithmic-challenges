#include <iostream>
#include <set>
using namespace std;
 
struct Node {
	char val;
	Node* left; Node* right;
};
 
Node* build(const string& pre, const string& in, int l1, int r1, int l2, int r2) {
	if (l1 > r1) return NULL;
	Node* t = new Node();
	t->val = pre[l1];
	set<char> s;
	int i = l2;
	while (in[i] != pre[l1]) {
		s.insert(in[i]);
		++i;
	}
	int j = l1 + 1;
	while (!s.empty()) {
		s.erase(pre[j]);
		j++;
	}
	t->left = build(pre, in, l1+1, j-1, l2, i-1);
	t->right = build(pre, in, j, r1, i+1, r2);
	return t;
}
 
void post(Node* t) {
	if (t != NULL) {
		post(t->left);
		post(t->right);
		cout << t->val;
	}
}
 
int main() {
	// your code goes here
	string pre, in;
	while (cin >> pre >> in) {
		int n = (int) pre.size();
		Node* root = build(pre, in, 0, n-1, 0, n-1);
		post(root);
		cout << endl;
	}
	return 0;
}
