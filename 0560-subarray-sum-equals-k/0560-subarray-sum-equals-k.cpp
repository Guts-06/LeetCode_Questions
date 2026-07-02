class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int pre=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            if(mp.find(pre-k)!=mp.end()){
                cnt += mp[pre-k];
            }
            mp[pre]++;
        }
        return cnt;
    }
};