class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        if(mp[nums[nums.size()/2]]==1){
            return true;
        }
        return false;
    }
};