class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==0) return 0;
        long long start=intervals[0][0];
        long long end=intervals[0][1];
        long long time=0;
        long long K=(brightness+2)/3;
        for(int i=1;i<intervals.size();i++){
            long long s=intervals[i][0];
            long long e=intervals[i][1];

            if(s<=end){
                end=max(end,e);
            }
            else{
                time+=end-start+1;
                start=s;
                end=e;
            }
        }
        time+=end-start+1;
        long long ans=time*K;
        return ans;
    }
};