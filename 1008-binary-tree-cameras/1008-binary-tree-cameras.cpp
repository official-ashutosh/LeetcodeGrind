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

    set<TreeNode *> s;

    void dfs(TreeNode *v, TreeNode *par, int &ans){
        if(v != NULL){
            dfs(v->left, v, ans);
            dfs(v->right, v, ans);

            if((par == NULL && !s.count(v)) || !s.count(v->left) || !s.count(v->right)){
                ans++;
                s.insert(v);
                s.insert(par);
                s.insert(v->left);
                s.insert(v->right);
            }
        }
    }

    int minCameraCover(TreeNode* root) {
        int ans = 0;
        s.insert(NULL);
        dfs(root, NULL, ans);

        return ans;
    }
};
