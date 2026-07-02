class Solution {
public:
    int maxsub(vector<int>& nums, int k){
        int n=nums.size();
        int cnt=0;
        int ans=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) cnt++;
            while(cnt>k){
                if(nums[left]%2){
                    cnt--;
                }
                left++;
            }
            ans+=i-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return maxsub(nums,k)-maxsub(nums,k-1);
    }
};