class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        if(units[0].size()==1){
            long long sum2=0;
            for(int i=0;i<m;i++){
                sum2+=units[i][0];
            }
            return sum2;
        }
        long long sum=0;

        long long bigmini=INT_MAX;
        long long bigmini2=INT_MAX;
        for(int i=0;i<m;i++){
            sort(units[i].begin(),units[i].end());
            int mini=units[i][0];
            int mini2=units[i][1];

            bigmini=min((int)bigmini,mini);
            bigmini2=min((int)bigmini2,mini2);

            sum+=mini2;
        }
        
        sum=sum-bigmini2+bigmini;
        return sum;
    }
};