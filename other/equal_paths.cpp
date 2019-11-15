// Finds all paths that sum up to a given value in a binary tree

#include <iostream>
#include <vector>
using namespace std;
 
struct Node {
	int d;
	Node* l;
	Node* r;
};
 
void print_paths(Node* n, vector<Node*>& v, int& sum, int k) {
	if (n != NULL) {
		v.push_back(n);
		sum += n -> d;
		if (sum == k) {
			for (auto m : v) cout << m -> d << " ";
			cout << endl;
		}
		print_paths(n -> l, v, sum, k);
		print_paths(n -> r, v, sum, k);
 
		sum = 0;
		v.clear();
		print_paths(n -> l, v, sum, k);
		sum = 0;
		v.clear();
		print_paths(n -> r, v, sum, k);
 
	}
}
 
int main() {
	// your code goes here
	Node* n1 = new Node();
	n1 -> d = 1;
	Node* n2 = new Node();
	n2 -> d = 2;
	Node* n3 = new Node();
	n3 -> d = 3;
	n1 -> l = n2;
	n2 -> l = n3;
	vector<Node*> v;
	int sum = 0;
	print_paths(n1, v, sum, 3);
	return 0;
}
