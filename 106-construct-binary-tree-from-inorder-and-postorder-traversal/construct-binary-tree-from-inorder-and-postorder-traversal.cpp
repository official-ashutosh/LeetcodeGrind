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

    unordered_map<int, int> mp;
    TreeNode *build(int st1, int en1, int st2, int en2, vector<int>&inorder, vector<int>&postorder){
        if(st1 > en1 || st2 > en2) return nullptr;

        TreeNode *root = new TreeNode(postorder[en2]);

        int md = mp[root->val];
        root->left = build(st1, md-1, st2, st2+md-st1-1, inorder, postorder);
        root->right = build(md+1, en1, st2+md-st1, en2-1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        return build(0, n-1, 0, n-1, inorder, postorder);    


    }
};