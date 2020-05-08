// Print n-ary tree post-order (without recursion)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
struct Node {
	int d;
	vector<Node*> v;
};
 
void post_print(Node* root) {
	if (root != NULL) {
		vector<int> res;
		stack<Node*> s;
		s.push(root);
		while (!s.empty()) {
			auto n = s.top(); s.pop();
			res.push_back(n->d);
			for (auto neigh: n->v)
				s.push(neigh);
		}
		for (auto it = res.rbegin(); it != res.rend(); ++it)
			cout << *it << endl;
	}
}
 
int main() {
	// your code goes here
	Node* n1 = new Node();
	Node* n2 = new Node();
	Node* n3 = new Node();
	Node* n4 = new Node();
	n1->d=1; n2->d=2; n3->d=3; n4->d=4;
	vector<Node*> v1 = {n2, n3};
	vector<Node*> v2 = {n4};
	n1->v=v1; n3->v=v2;
	post_print(n1);
	return 0;
}
