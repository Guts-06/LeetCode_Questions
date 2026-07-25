class Solution {
public:
    int f(int index,vector<int>& cost , vector<int>&dp){
        if(index<=1){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        
        dp[index]=min(f(index-1,cost,dp)+cost[index-1],f(index-2,cost,dp)+cost[index-2]);
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        dp[0]=0;
        dp[1]=0;
        int index=cost.size();
        return f(index,cost,dp);
    }
};