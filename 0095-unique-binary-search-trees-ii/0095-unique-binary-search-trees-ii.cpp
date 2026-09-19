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
    vector<TreeNode*> solve(int l, int r){
        vector<TreeNode*> res;

        if(l > r){
            res.push_back(nullptr);
            return res;
        }

        for(int root = l; root <= r; root++){
            vector<TreeNode*> left = solve(l, root-1);
            vector<TreeNode*> right = solve(root+1, r);

            for(auto L : left){
                for(auto R : right){
                    TreeNode* node = new TreeNode(root);
                    node->left = L;
                    node->right = R;
                    res.push_back(node);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};