// Check if a tree is a subtree of another tree

#include <iostream>
using namespace std;
 
struct Node {
	int d;
	Node* l;
	Node* r;
};
 
bool match(Node* t1, Node* t2) {
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL || t2 == NULL) return false;
	if (t1 -> d != t2 -> d) return false;
	return match(t1 -> l, t2 -> l) && match(t1 -> r, t2 -> r);
}
 
bool contains(Node* t1, Node* t2) {
	if (t1 == NULL) return false;
	if (t1 -> d == t2 -> d && match(t1, t2)) return true;
	return contains(t1 -> l, t2) || contains(t1 -> r, t2);
}
 
bool subtree(Node* t1, Node* t2) {
	if (t2 == NULL) return true;
	return contains(t1, t2);
}
 
int main() {
	// your code goes here
	return 0;
}
