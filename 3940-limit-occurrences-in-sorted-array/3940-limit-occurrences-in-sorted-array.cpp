class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=1;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            
            if(nums[i]==nums[i-1]) cnt++;
            else{
                cnt=1;
            }
            if(cnt<=k){
                ans.push_back(nums[i]);
            }
            }
        return ans;
        
    }
};