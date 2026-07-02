class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
                   mp[nums[i]]++;
        } 

        vector <int> ans;
        for(auto it : mp){
            int el=it.first;
            int cnt=it.second;

            if(cnt>n/3){
                ans.push_back(el);
            }
        }
        return ans;   
    }
};