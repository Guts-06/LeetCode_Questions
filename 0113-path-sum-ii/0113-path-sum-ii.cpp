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
    void dfs(TreeNode* node, int targetSum ,vector<int>&path,vector<vector<int>>&ans){
        if(node==nullptr){
            return ;
        }
        targetSum-=node->val;
        path.push_back(node->val);
        if(node->left==nullptr&&node->right==nullptr&&targetSum==0){
            ans.push_back(path);
        }
        dfs(node->left,targetSum,path,ans);
        dfs(node->right,targetSum,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(root,targetSum,path,ans);
        return ans;
    }
};