// Given two linked lists, returns a list containing the sum of values from the two lists

#include <iostream>
#include <unordered_set>
using namespace std;
 
struct Node {
	int d;
	Node* next;
};
 
Node* add(Node* h1, Node* h2) {
	Node* l1 = h1; Node* l2 = h2;
	Node* head; Node* last;
	int rem = 0;
	while (l1 != NULL && l2 != NULL) {
		int sum = (l1 -> d) + (l2 -> d) + rem;
		Node* n = new Node();
		n -> d = sum % 10;
		rem = sum / 10;
		if (head == NULL) {
			head = n;
			last = n;
		} else {
			last -> next = n;
			last = n;
		}
		l1 = l1 -> next;
		l2 = l2 -> next;
	}
	while (l1 != NULL) {
		int sum = (l1 -> d) + rem;
		Node* n = new Node();
		n -> d = sum % 10;
		rem = sum / 10;
		if (head == NULL) {
			head = n;
			last = n;
		} else {
			last -> next = n;
			last = n;
		}
		l1 = l1 -> next;
	}
	while (l2 != NULL) {
		int sum = (l2 -> d) + rem;
		Node* n = new Node();
		n -> d = sum % 10;
		rem = sum / 10;
		if (head == NULL) {
			head = n;
			last = n;
		} else {
			last -> next = n;
			last = n;
		}
		l2 = l2 -> next;
	}
	return head;
}
 
Node* remove(Node* head) {
	if (head == NULL) return head;
	unordered_set<int> s;
	Node* n = head;
	s.insert(n -> d);
	while (n -> next != NULL) {
		if (s.find(n -> next -> d) == s.end())
			s.insert(n -> next -> d);
		else
			n -> next = n -> next -> next;
		n = n -> next;
	}
}
 
int main() {
	// your code goes here
	Node* n1; Node* n2; Node* n3; Node* n4; Node* n5;
	n1 -> d = 3;
	n2 -> d = 1;
	n3 -> d = 5;
	n4 -> d = 5;
	n5 -> d = 9;
	n1 -> next = n2;
	n2 -> next = n3;
	n4 -> next = n5;
	Node* n = add(n1, n4);
	while (n != NULL) {
		cout << n -> d << " ";
		n = n -> next;
	}
	return 0;
}
