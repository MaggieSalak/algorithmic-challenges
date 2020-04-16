// Finds path between two nodes in a BST tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Node {
	int d;
	Node* l;
	Node* r;
};
 
void one_path(Node* t, int a, vector<int>& acc) {
	if (t == NULL) return;
	acc.push_back(t->d);
	if (a == t->d) return;
	else if (a < t->d) one_path(t->l, a, acc);
	else one_path(t->r, a, acc);
}
 
vector<int> path(Node* t, int a, int b) {
	if (a < t->d && b < t->d) return path(t->l, a, b);
	else if (a > t->d && b > t->d) return path(t->r, a, b);
	else if (min(a,b) <= t->d && max(a,b) >= t->d) {
		vector<int> v1, v2;
		one_path(t, min(a,b), v1);
		one_path(t, max(a,b), v2);
		reverse(v1.begin(), v1.end());
		v1.pop_back();
		for (auto x: v2) v1.push_back(x);
		return v1;
	}
}
 
int main() {
	// your code goes here
	Node* n1 = new Node(); Node* n2 = new Node(); Node* n3 = new Node();Node* n4 = new Node();Node* n5 = new Node();Node* n6 = new Node();
	n1->d=5; n2->d=2; n3->d=7; n4->d=4; n5->d=6; n6->d=8;
	n1->l=n2; n1->r=n3; n2->r=n4; n3->l = n5; n3->r=n6;
	auto res = path(n1, 8, 5);
	for (auto x: res) cout << x << " ";
	return 0;
}
