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
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* cur = root;

        while(cur){
            if(cur->left){
                TreeNode* temp = cur->left;

                while(temp->right)
                    temp = temp->right;

                temp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }

            cur = cur->right;
        }
    }
};