// Implementation of various graph algorithms - topological sort (recursive and iterative), BFS, DFS

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
 
struct Node {
	int data;
	bool visited;
	vector<Node*> neigh;
};
 
stack<Node*> top_sort_iter(Node* n) {
	stack<pair<Node*, int>> s;
	stack<Node*> res;
	n -> visited = true;
	s.push(make_pair(n, 0));
	while (!s.empty()) {
		auto p = s.top();
		s.pop();
		if (p.second == (int) (p.first -> neigh).size())
			res.push(p.first);
		else {
			s.push(make_pair(p.first, p.second + 1));
			Node* m = p.first -> neigh[p.second];
			if (!m -> visited) {
				m -> visited = true;
				s.push(make_pair(m, 0));
			}
		}
	}
	return res;
}
 
void run_top_sort_iter(Node* root) {
	stack<Node*> s;
	if (root != NULL)
		s = top_sort_iter(root);
	while (!s.empty()) {
		cout << s.top() -> data << endl;
		s.pop();
	}
}
 
void top_sort(Node* n, stack<Node*>& s) {
	n -> visited = true;
	for (auto m : n -> neigh) 
		if (!m -> visited)
			top_sort(m, s);
	s.push(n);
}	
 
void run_top_sort(Node* root) {
	stack<Node*> s;
	if (root != NULL)
		top_sort(root, s);
	while (!s.empty()) {
		cout << s.top() -> data << endl;
		s.pop();
	}
}
 
void dfs_rec(Node* n) {
	if (n != NULL) {
		n -> visited = true;
		cout << n -> data << endl;
		for (auto m : n -> neigh) 
			if (!m -> visited)
				dfs_rec(m);
	}
}
 
void dfs_iter(Node* n) {
	if (n != NULL) {
		stack<Node*> s;
		n -> visited = true;
		s.push(n);
		while (!s.empty()) {
			Node* m = s.top();
			cout << m -> data << endl;
			s.pop();
			for (auto t : m -> neigh) 
				if (!t -> visited) {
					t -> visited = true;
					s.push(t);
				}
		}
	}
}	
 
void bfs(Node* n) {
	if (n != NULL) {
		queue<Node*> q;
		n -> visited = true;
		q.push(n);
		while (!q.empty()) {
			Node* m = q.front();
			cout << m -> data << endl;
			q.pop();
			for (auto t : m -> neigh) 
				if (!t -> visited) {
					t -> visited = true;
					q.push(t);
				}
		}
	}
}
 
 
int main() {
	// your code goes here
	Node* n1 = new Node();
	n1 -> data = 1;
	Node* n2 = new Node();
	n2 -> data = 2;
	Node* n3 = new Node();
	n3 -> data = 3;
	Node* n4 = new Node();
	n4 -> data = 4;
	Node* n5 = new Node();
	n5 -> data = 5;
	n1 -> neigh = {n2, n3};
	n2 -> neigh = {n5};
	n3 -> neigh = {n2, n4};
	run_top_sort_iter(n1);
	//bfs(n1);
	return 0;
}
