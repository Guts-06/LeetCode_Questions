class Solution {
public:
    void backtrack(int start,vector<int>&temp,vector<vector<int>>&ans,int sum,vector<int> &candidates,int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            int el=candidates[i];
            backtrack(i,temp,ans,sum+el,candidates,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int sum=0;
        backtrack(0,temp,ans,sum,candidates,target);
        return ans;
    }
};