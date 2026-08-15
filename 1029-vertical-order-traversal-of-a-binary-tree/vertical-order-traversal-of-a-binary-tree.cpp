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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;      // column ↓ row ↓ values
        queue<pair<TreeNode*, pair<int, int>>> q;  // treeNode ↓ column ↓ row

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto [node, p] = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            mp[x][y].insert(node->val);

            if(node->left)
                q.push({node->left, {x-1, y+1}});

            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;

        for(auto [x, levels] : mp){
            vector<int> temp;

            for(auto [y, vals] : levels){
                for(auto val : vals)
                    temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};