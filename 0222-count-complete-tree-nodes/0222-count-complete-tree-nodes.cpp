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
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh=left(root->left);
        int rh=right(root->right);
        if(lh==rh){
            return (2^lh)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
        // return 0;
    }
    int left(TreeNode* node){
        int cnt=1;
        while(node){
            node=node->left;
            cnt++;
        }
        return cnt;
    }
    int right(TreeNode* node){
        int cnt=0;
        while(node){
            node=node->right;
            cnt++;
        }
        return cnt;
    }
};