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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long ans = 0;

        while(!q.empty()){
            int n = q.size();
            long long st = q.front().second;
            long long en = st;

            while(n--){
                auto [node, id] = q.front();
                q.pop();

                id -= st;
                en = id;

                if(node->left)
                    q.push({node->left, 2 * id});

                if(node->right)
                    q.push({node->right, 2 * id + 1});
            }

            ans = max(ans, en + 1);
        }

        return ans;
    }
};