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

    int dfs(TreeNode* root, int& mn, int& mx, bool& bst){
        if(!root){
            mn = INT_MAX;
            mx = INT_MIN;
            bst = true;
            return 0;
        }

        int lmn, lmx, rmn, rmx;
        bool lb, rb;

        int lsum = dfs(root->left, lmn, lmx, lb);
        int rsum = dfs(root->right, rmn, rmx, rb);

        if(lb && rb && lmx < root->val && root->val < rmn){
            bst = true;
            mn = min(lmn, root->val);
            mx = max(rmx, root->val);

            int sum = lsum + rsum + root->val;
            ans = max(ans, sum);

            return sum;
        }

        bst = false;
        mn = INT_MIN;
        mx = INT_MAX;

        return 0;
    }

    int maxSumBST(TreeNode* root) {
        int mn, mx;
        bool bst;
        dfs(root, mn, mx, bst);
        return ans;
    }
};