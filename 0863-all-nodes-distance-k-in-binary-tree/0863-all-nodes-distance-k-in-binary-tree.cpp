/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }

        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);

        int dist = 0;

        while(!q.empty() && dist < k){
            int n = q.size();

            while(n--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if(par.count(node) && !vis.count(par[node])){
                    vis.insert(par[node]);
                    q.push(par[node]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};