class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int> sumarr(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                sumarr[i]=sumarr[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                sumarr[i-1]=max(sumarr[i]+1,sumarr[i-1]);
            }
        }
        int sum=accumulate(sumarr.begin(),sumarr.end(),0);
        return sum;
    }
};