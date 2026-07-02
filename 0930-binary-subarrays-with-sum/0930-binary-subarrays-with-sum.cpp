class Solution {
public:
    int maxCount(vector<int>& nums, int goal){
        int left=0;
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt+=i-left+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0){
            return maxCount(nums,0);
        }
        return maxCount(nums,goal)-maxCount(nums,goal-1);
    }
};