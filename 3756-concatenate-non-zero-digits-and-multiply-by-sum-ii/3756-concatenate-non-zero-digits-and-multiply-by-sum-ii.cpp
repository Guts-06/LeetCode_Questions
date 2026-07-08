class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        long long MOD=1e9+7;
        int m=queries.size();
        vector<int>PreSum(n+1,0);
        vector<long long>PreVal(n+1,0);
        vector<int> NonZero(n+1,0);
        vector<long long> power(n+1,1);
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*10)%MOD;
        }
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            PreSum[i+1]=num+PreSum[i];
            if(num!=0){
                NonZero[i+1]=NonZero[i]+1;
                PreVal[i+1]=(PreVal[i]*10+num)%MOD;
            }
            else{
                NonZero[i+1]=NonZero[i];
                PreVal[i+1]=PreVal[i];
            }
        }
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            long long sum=PreSum[r+1]-PreSum[l];
            long long x=(PreVal[r+1]-(power[NonZero[r+1]-NonZero[l]]*PreVal[l]%MOD)+MOD)%MOD;

            ans[i]=(x*sum)%MOD;
        }
        return ans;
    }
};