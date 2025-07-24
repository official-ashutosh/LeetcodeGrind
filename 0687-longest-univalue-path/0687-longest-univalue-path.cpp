class Solution {
public:

    int ans = 0;
    int dfs(TreeNode *root){
        if(!root) return 0;

        int ans2 = 0, ans3 = 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        if(root->left && root->left->val == root->val){
            ans2 = left;
        }

        if(root->right && root->right->val == root->val){
            ans3 = right;
        }

        ans = max(ans, ans2+ans3); 
        return max(ans2, ans3) + 1;  
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);

        return ans;
    }
};
