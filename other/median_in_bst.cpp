#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val) {}
};

int getNth(TreeNode* t, int& cur, int n) {
	if (t == NULL) 
		return INT_MAX;
	
	int leftVal = getNth(t->left, cur, n);	
	if (leftVal != INT_MAX)
		return leftVal;
	
	cur++;
	if (cur == n) 
		return t->val;
	
	return getNth(t->right, cur, n);
}

int getNthTreeElement(TreeNode* t, int n) {
	int cur = 0;
	return getNth(t, cur, n);
}

int countTreeElements(TreeNode* t) {
	if (t == NULL) return 0;
	return countTreeElements(t->left) + 1 + countTreeElements(t->right);
}

double getMedian(TreeNode* t) {
	int elements = countTreeElements(t);
	cout << elements << endl;
	if (elements % 2 == 1)
		return getNthTreeElement(t, elements/2 + 1);
	int el1 = getNthTreeElement(t, elements/2);
	int el2 = getNthTreeElement(t, elements/2 + 1);
	cout << el1 << " " << el2 << endl;
	return (el1 + el2) / (double) 2;
}


int main() {
	// your code goes here
	TreeNode* t = new TreeNode(2);
	t->left = new TreeNode(1);
	t->right = new TreeNode(4);
	t->right->left = new TreeNode(3);
	cout << getMedian(t) << endl;
	return 0;
}
