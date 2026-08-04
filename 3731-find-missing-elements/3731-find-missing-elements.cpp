class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool>vis(101);
        vector<int>ans;
        int maxi=INT_MIN,mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vis[nums[i]]=true;
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        for(int i=mini;i<=maxi;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};