#include <iostream>
#include <vector>
using namespace std;

struct PairResult {
	int x;
	int y;
	bool found = false;
};

PairResult findNumbersWithSum(const vector<int>& v, int sum) {
	int n = v.size();
	int left = 0, right = n-1;
	
	PairResult res;
	
	while (left < right) {
		if (v[left] + v[right] == sum) {
			res.found = true;
			res.x = v[left];
			res.y = v[right];
			break;
		} else if (v[left] + v[right] < sum) {
			++left;
		} else {
			--right;
		}
	}
	return res;
}

int main() {
	// your code goes here
	vector<int> v {1, 4, 6, 6, 7};
	auto res = findNumbersWithSum(v, 10);
	cout << res.found << res.x << res.y << endl;
	return 0;
}
