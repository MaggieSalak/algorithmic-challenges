class Solution {
public:
    
    void traverse(TreeNode* t, vector<int>& v) {
        if (t != NULL) {
            traverse(t->left, v);
            v.push_back(t->val);
            traverse(t->right, v);
        }
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;   
    }
};
