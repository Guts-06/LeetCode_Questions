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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        int count=0;
        while(q.size()!=0){
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                level.push_back(node->val);
            }
            if(count%2==1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            count++;
        }
        return ans;
    }
};