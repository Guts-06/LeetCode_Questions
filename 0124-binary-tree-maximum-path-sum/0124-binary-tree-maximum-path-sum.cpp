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
    int maxi=INT_MIN;
    int mPS(TreeNode* node,int maxii){
        if(node==nullptr){
            return 0;
        }
        int leftsum=max(0,mPS(node->left,maxi));
        int rightsum=max(0,mPS(node->right,maxi));
        maxi=max(maxi,leftsum+rightsum+node->val);


        return max(leftsum,rightsum)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        mPS(root,maxi);
        return maxi;
    }
};