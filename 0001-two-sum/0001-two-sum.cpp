class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int first=nums[i];
            int second=target - first;
            if(mpp.find(second)!=mpp.end()){
                return{mpp[second],i};
            }
            mpp[first]=i;
        }
        return{-1,-1};
    }
};