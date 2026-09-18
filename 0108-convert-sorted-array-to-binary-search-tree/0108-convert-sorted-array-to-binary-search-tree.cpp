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

    TreeNode* func(vector<int>& nums, int le, int ri) {
        if(le > ri){
            return nullptr;
        }
        
        int mid = (le+ri)/ 2;
        
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = func(nums, le, mid-1);
        node->right = func(nums, mid+1, ri);
        
        return node;
    } 

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);        
    } 
};