#include <iostream>
#include <unordered_map>

using namespace std;

class MyException : public exception {
} ex;

struct Node {
	int val;
	Node* nxt;
	Node* prev;
};

class LRUCache {
	private:
		int cap; 
		unordered_map<int, pair<string, Node*>> dict;
		Node* head;
		Node* tail;
		
		void move_front(int key) {
			auto it = dict.find(key);
			Node* n = it->second.second;
			if (n == head) 
				return;
			Node* n_prev = n->prev;
			Node* n_next = n->nxt;
			n_prev->nxt = n->nxt;
			if (n != tail)
				n->nxt->prev = n_prev;
			else
				tail = n_prev;
			n->nxt = head;
			n->prev = NULL;
			head->prev = n;
			head = n;
		}
		
		void delete_lru() {
			Node* t = tail;
			Node* t_prev = t->prev;
			t_prev->nxt = NULL;
			tail = t_prev;
			dict.erase(t->val);
			delete(t);
		}

	public:
		LRUCache(int capa) {
			cap = capa;
			head = NULL;
			tail = NULL;
		}
		
		void print() {
			Node* n = head;
			while (n != NULL) {
				cout << n->val << " ";
				n = n->nxt;
			}
			cout << endl;
		}
	
		void add(int key, string val) {
			auto it = dict.find(key);
			if (it == dict.end()) {
				if (dict.size() >= cap) {
					delete_lru();
				}
				
				Node* n = new Node();
				n->val = key;
				n->nxt = head;
				if (head != NULL) 
					head->prev = n;
				head = n;
				if (tail == NULL)
					tail = head;
			} else {
				move_front(key);
			}
			
			dict[key] = make_pair(val, head);
		}
	
		string get(int key) {
			auto it = dict.find(key);
			if (it == dict.end()) {
				throw ex;
			}
			move_front(key);
			return dict[key].first;
		}
	
};

int main() {
	LRUCache cache(2);
	cache.print();
	cache.add(1, "a");
	cache.print();
	cache.add(2, "b");
	cache.print();
	cache.add(3, "c");
	cache.print();
	cache.add(2, "d");
	cache.print();
	cout << cache.get(2) << " " << cache.get(3) << endl;
	return 0;
}
