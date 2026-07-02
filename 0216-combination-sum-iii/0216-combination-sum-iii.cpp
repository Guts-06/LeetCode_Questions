class Solution {
public:
    void backtrack(int start,int sum, vector<int>&temp,vector<vector<int>>&ans,int k,int n){
        if(temp.size()==k&&sum==n){
            ans.push_back(temp);
            return;
        }
        if(sum>n||temp.size()>k){
            return;
        }
        for(int i=start;i<=9;i++){
            temp.push_back(i);
            backtrack(i+1,sum+i,temp,ans,k,n);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>>ans;
        int sum=0;
        int start=1;
        backtrack(start,sum,temp,ans,k,n);
        return ans;
    }
};