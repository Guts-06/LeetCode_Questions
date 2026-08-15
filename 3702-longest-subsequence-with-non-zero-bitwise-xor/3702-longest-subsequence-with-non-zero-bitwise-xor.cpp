class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool nonzero=false;
        for(auto it:nums){
            xr^=it;
            if(it!=0){
                nonzero=true;
            }
        }
        if(xr!=0){
            return (int)nums.size();
        }
        if(nonzero){
            return (int)nums.size()-1;
        }
        return 0;
    }
};