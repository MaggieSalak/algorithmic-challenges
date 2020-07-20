class Solution {
public:
    void traverse(TreeNode* root, vector<int>& v) {
        if (root->left != NULL) {
            traverse(root->left, v);
        }
        
        v.push_back(root->val);
        
        if (root->right != NULL) {
            traverse(root->right, v);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        traverse(root, v);
        if (v.size() < k) {
            return -1;
        }
        return v[k-1];
    }
};
