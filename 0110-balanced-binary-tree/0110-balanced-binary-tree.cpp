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
    int height(TreeNode* node,int h){
        if(node==nullptr){
            return h;
        }
        int lh=height(node->left,h+1);
        int rh=height(node->right,h+1);

        if(abs(lh-rh)>1) return -2;
        return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        // if(root==nullptr) return true;

        // int lh=height(root->left,0);
        // int rh=height(root->right,0);

        // if(abs(lh-rh)>1) return false;

        // return isBalanced(root->left)&&isBalanced(root->right);

        return height(root,0)!=-2;
    }
};