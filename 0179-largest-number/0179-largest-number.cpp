class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr(nums.size());
        string ans="";
        for(int i=0;i<nums.size();i++){
            arr[i]=to_string(nums[i]);
        }
        sort(arr.begin(),arr.end(),[](string a,string b){
            return a+b>b+a;
        });
        for(auto it:arr){
            ans+=it;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};