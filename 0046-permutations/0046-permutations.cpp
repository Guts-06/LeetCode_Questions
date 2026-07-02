class Solution {
public:
    void back(vector<int>&used,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=1;
            back(used,nums,temp,ans);
            temp.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>used(nums.size(),0);
        back(used,nums,temp,ans);
        return ans;
    }
};