// Finds the most frequent value in a BST tree

#include <iostream>
using namespace std;
 
struct Node {
	int d;
	Node* l;
	Node* r;
};
 
struct result {
	pair<int, int> most_freq;
	int root_val;
};
 
result occur(Node* t, int k) {
	result res; res.root_val = 0; res.most_freq = make_pair(-1, 0);
	if (t != NULL) {
		auto left = occur(t->l, t->d);
		auto right = occur(t->r, t->d);
		int node_val = 1 + left.root_val + right.root_val;
		if (node_val >= left.most_freq.second && node_val >= right.most_freq.second)
			res.most_freq = make_pair(t->d, node_val);
		else if (left.most_freq.second >= node_val && left.most_freq.second >= right.most_freq.second)
			res.most_freq = left.most_freq;
		else res.most_freq = right.most_freq;
		if (t-> d == k) res.root_val = node_val;
	}
	return res;
}
 
pair<int, int> most_freq(Node* t) {
	auto res = occur(t, -1);
	cout << res.most_freq.first << " " << res.most_freq.second << endl;
	return res.most_freq;
}
 
int main() {
	// your code goes here
	Node* n1 = new Node(); Node* n2 = new Node(); Node* n3 = new Node(); Node* n4 = new Node(); 
	Node* n5 = new Node(); Node* n6 = new Node(); Node* n7 = new Node();
	n1->d=6; n2->d=5; n3->d=6; n4->d=5; n5->d=5; n6->d=8; n7->d=7;
	n1->l=n2; n1->r=n3; n2->l=n4; n2->r=n5; n3->r=n6; n6->l=n7;
	auto p = most_freq(n1);
	return 0;
}
