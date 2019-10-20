#include <iostream>
#include <vector>
using namespace std;
 
class IntervalTree {
	private:
		int n;
		vector<int> tree;
 
		int calc(int ind, int cur_l, int cur_r, int l, int r) {
			if (r < cur_l || l > cur_r)
				return 0;
			if (l <= cur_l && cur_r <= r)
				return tree[ind];
			return calc(ind*2, cur_l, cur_l+(cur_r-cur_l)/2, l, r) + calc(ind*2+1, cur_l+(cur_r-cur_l)/2+1, cur_r, l, r);
		}
 
	public:
		void init(const vector<int>& v) {
			n = (int) v.size();
			tree.resize(2 * n);
			for (int i = 0; i < n; ++i)
				tree[n+i] = v[i];
			for (int i = n-1; i > 0; --i)
				tree[i] = tree[i*2] + tree[i*2+1];
		}
 
		void update(int k, int val) {
			int i = n + k;
			int diff = val - tree[i];
			tree[i] = val;
			i = i/2;
			while (i > 0) {
				tree[i] += diff;
				i /= 2;
			}
		}
 
		int sum(int l, int r) {
			return calc(1, 1, n, l, r);
		}
		void print() {
			for (auto x : tree)
				cout << x << " ";
			cout << endl;
		}
};
 
int main() {
	// your code goes here
	IntervalTree t;
	vector<int> v = {1, 1, 1, 1};
	t.init(v);
	for (int i = 0; i < 4; ++i){
		t.update(i, 2);
		t.print();
		cout << t.sum(1, 3) << endl;
	}
	return 0;
}
