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
    TreeNode* FindMin(TreeNode* root){
        while(root->left){
        root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;

        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==nullptr && root->right==nullptr) {
                delete root;
                return nullptr;
            }
            else if(!root->left||!root->right){
                if(root->left){
                    TreeNode* child=root->left;
                    delete root;
                    return child;
                }
                else{
                TreeNode* child=root->right;
                delete root;
                return child;
                }
            }
            else{
                TreeNode* node=FindMin(root->right);
                root->val=node->val;
                root->right=deleteNode(root->right,node->val);
                return root;
            }
        }
        return root;
    }
};