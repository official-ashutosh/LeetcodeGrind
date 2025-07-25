class Solution {
public:
    int minDiff;
    int prevVal;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prevVal != -1) {
            minDiff = min(minDiff, node->val - prevVal);
        }
        prevVal = node->val;
        inorder(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        prevVal = -1;
        inorder(root);
        return minDiff;
    }
};
