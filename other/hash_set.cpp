#include <iostream>
#include <vector>
using namespace std;

const int Ratio = 1;
const int InitSize = 5;

class Node {
	public:
		int value;
		Node* next;
		Node(int val) : value(val) {}
	
};

class HashSet {
	private:
		vector<Node*> v;
		int size;
		void resize();
		bool insertValue(int val);
	
	public:
		HashSet();
		void insert(int val);
		void erase(int val);
		int count();
		bool contains(int val);
		void print();
};

HashSet::HashSet() {
	v = vector<Node*>(InitSize);
	size = 0;
}

bool HashSet::insertValue(int val) {
	Node* valNode = new Node(val);
		
	int index = val % v.size();
	
	if (v[index] == NULL) { 
		v[index] = valNode;
		return true;
	}
	
	Node* n = v[index];
	if (n->value == val) 
		return false;
		
	while (n->next != NULL) {
		n = n->next;
		if (n->value == val)
			return false;
	}
	n->next = valNode;
	return true;
}

void HashSet::insert(int val) {
	bool inserted = insertValue(val);
	if (inserted) {
		++size;
		if (size/v.size() >= Ratio)
			resize();
	}
}

void HashSet::erase(int val) {
	int index = val % v.size();
	Node* n = v[index];
	if (n == NULL) return;
	if (n->value == val) {
		v[index] = n->next;
		--size;
		return;
	}
	while (n->next != NULL && n->next->value != val)
		n = n->next;
	if (n->next != NULL) {
		n->next = n->next->next;
		--size;
	}
}

int HashSet::count() {
	return size;
}

bool HashSet::contains(int val) {
	int index = val % v.size();
	Node* n = v[index];
	while (n != NULL) {
		if (n->value == val)
			return true;
		n = n->next;
	}
	return false;
}

void HashSet::resize() {
	vector<Node*> old = v;
	v = vector<Node*>(2 * old.size());
	
	for (int i = 0; i < old.size(); ++i) {
		Node* n = old[i];
		while (n != NULL) {
			insertValue(n->value);
			n = n->next;
		}
	}
}

void HashSet::print() {
	for (int i = 0; i < v.size(); ++i) {
		Node* n = v[i];
		while (n != NULL) {
			cout << n->value << ",";
			n = n->next;
		}
		cout << endl;
	}
	cout << "size " << v.size() << endl;
}
