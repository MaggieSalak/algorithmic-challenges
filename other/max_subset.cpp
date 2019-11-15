// Finds a max-sum non-connected subset in a binary tree 

#include <iostream>
using namespace std;
 
struct Node {
	int d;
	Node* l;
	Node* r;
};
 
pair<int, int> subset(Node* t) {
	if (t == NULL) return make_pair(0, 0);
	auto left = subset(t -> l);
	auto right = subset(t -> r);
	int max_incl = left.second + right.second + t -> d;
	int max_excl = max(left.first, left.second) + max(right.first, right.second);
	return make_pair(max_incl, max_excl);
}
 
int max_subset(Node* t) {
	auto res = subset(t);
	return max(res.first, res.second);
}
 
 
int calc(Node* cur, bool take) {
 	if (cur == NULL) return 0;
 	int n1 = 0;
 	if (take)
 		n1 = cur -> d + calc(cur -> l, false) + calc(cur -> r, false);
 	int n2 = calc(cur -> l, true) + calc(cur -> r, true);
 	return max(n1, n2);
}
 
int max_subset2(Node* t) {
 	return calc(t, true);
}
 
int main() {
	// your code goes here
	Node* n1 = new Node();
	Node* n2 = new Node();
	Node* n3 = new Node();
	n1 -> d = 1;
	n2 -> d = 2;
	n3 -> d = 3;
	n1 -> l = n2;
	n1 -> r = n3;
	cout << max_subset(n1) << endl;
	return 0;
}
