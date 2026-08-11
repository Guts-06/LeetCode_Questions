class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
                continue;
            }
            else{
                break;
            }
        }
        while(true){
        if(mp.find(sum)!=mp.end()){
            sum++;
        }
        else{
            return sum;
        }
        }
        return sum;
    }
};