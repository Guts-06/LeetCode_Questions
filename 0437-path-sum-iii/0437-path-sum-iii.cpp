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
    int currentSum=0;
    int dfs(TreeNode* node,long currentSum,int targetSum,unordered_map<long,int>&mp){
        if(node==nullptr) return 0;
        currentSum+=node->val;
        int count=mp[currentSum-(long)targetSum];
        mp[currentSum]++;
        count+=dfs(node->left,currentSum,targetSum,mp);
        count+=dfs(node->right,currentSum,targetSum,mp);

        mp[currentSum]--;
        if(mp[currentSum]==0){
            mp.erase(currentSum);
        }
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int>mp;
        mp[0]=1;
        return dfs(root,0,targetSum,mp);
        
    }
};