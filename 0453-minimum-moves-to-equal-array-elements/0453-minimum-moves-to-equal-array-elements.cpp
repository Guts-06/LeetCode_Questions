class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int target=n*mini;
        int sum=accumulate(nums.begin(),nums.end(),0);
        return sum-target;
        
    }
};