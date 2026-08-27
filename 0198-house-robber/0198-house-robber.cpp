class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        // vector<int>dp(nums.size(),-1);
        int prevprev=nums[0];
        int prev=max(nums[0],nums[1]);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int pick=nums[i]+prevprev;
            int notpick=prev;
            prevprev=prev;
            prev=max(pick,notpick);
            
            // dp[i]=max(pick,notpick);
        }
        return prev;
    }
};