// Detect if a directed graph contains a cycle

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
 
struct Node {
	int d;
	bool visited;
	bool rec_stack;
	vector<Node*> neigh;
};
 
bool print_cycle(Node* n, vector<Node*>& v) {
	if (n == NULL) return false;
	n -> visited = true;
	n -> rec_stack = true;
	v.push_back(n);
	for (auto m : n -> neigh) {
		if (!m -> visited && print_cycle(m, v))
			return true;
		if (m -> rec_stack) {
			for (auto x : v)
				cout << x -> d << " ";
			cout << m -> d << endl;
			return true;
		}
	}
	n -> rec_stack = false;
	v.pop_back();
	return false;
}
 
bool cyclic(Node* n) {
	if (n == NULL) return false;
	n -> visited = true;
	n -> rec_stack = true;
	for (auto m : n -> neigh) {
		if (!m -> visited && cyclic(m)) 
			return true;
		if (m -> rec_stack)
			return true;
	}
	n -> rec_stack = false;
	return false;
}
 
 
int main() {
	// your code goes here
	Node* n1 = new Node();
	Node* n2 = new Node();
	Node* n3 = new Node();
	n1 -> d = 1;
	n2 -> d = 2;
	n3 -> d = 3;
	n1 -> neigh = {n2};
	n2 -> neigh = {n3};
	n3 -> neigh = {n1};
	vector<Node*> v;
	if (print_cycle(n1, v)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
