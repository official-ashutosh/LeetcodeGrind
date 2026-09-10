/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans = 0;

    pair<int, int> func(TreeNode * root){
        if(root == NULL) return {0, 0};

        auto le = func(root->left);
        auto ri = func(root->right);

        int sum = le.first + ri.first + root->val;
        int ct = le.second + ri.second + 1;

        if(root->val == sum/ct) ans++;
        return {sum, ct};
    }

    int averageOfSubtree(TreeNode* root) {
        func(root);
        return ans;    
    }
};