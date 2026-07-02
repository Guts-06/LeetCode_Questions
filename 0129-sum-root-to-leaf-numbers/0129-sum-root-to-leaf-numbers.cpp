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
    int ans=0;
    void dfs(TreeNode* node,int &ans,string temp){
        if(node==nullptr)return;

        temp+=to_string(node->val);
        if(node->left) dfs(node->left,ans,temp);
        if(node->right) dfs(node->right,ans,temp);
        int n=stoi(temp);
        if(node->left==nullptr&&node->right==nullptr){
            ans+=n;
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,ans,"");
        return ans;
    }
};