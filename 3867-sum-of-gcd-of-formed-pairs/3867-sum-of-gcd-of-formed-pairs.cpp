class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long curr=1;
        long long  mx=1;
        for(int i=0;i<n;i++){
            curr=nums[i];
            mx=max(mx,curr);
            nums[i]=gcd(mx,curr);
        }
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum+=(long long)gcd(nums[i],nums[n-1-i]);
        }
        return sum; 
    }
};