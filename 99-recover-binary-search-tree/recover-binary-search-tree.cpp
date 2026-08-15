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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr;

        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();

            if(prev && prev->val > cur->val){
                if(!first) first = prev;
                second = cur;
            }

            prev = cur;
            cur = cur->right;
        }

        swap(first->val, second->val);
    }
};