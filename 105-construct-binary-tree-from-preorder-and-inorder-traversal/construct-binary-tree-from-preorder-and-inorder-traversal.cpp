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

    int idx;
    unordered_map<int, int> mp;

public:

    TreeNode *build(int st, int en, vector<int>&preorder){
        if(st > en) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        int md = mp[root->val];

        root->left = build(st, md-1, preorder);
        root->right = build(md+1, en, preorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        idx = 0;
        return build(0, n-1, preorder);
    }
};