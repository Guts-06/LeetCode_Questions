class Solution {
public:
    int f(int i,int sum,vector<int>& nums, int target){
        if(i<0){
            return sum==target;
        }

        int take=f(i-1,sum+nums[i],nums,target);
        int nottake=f(i-1,sum-nums[i],nums,target);
        return take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,0,nums,target);
    }
};