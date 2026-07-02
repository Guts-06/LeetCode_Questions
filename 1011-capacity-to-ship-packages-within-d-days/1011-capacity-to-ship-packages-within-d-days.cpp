class Solution {
public:
int isPossible(vector<int>& weights, int days,int mid){
    int daycount=1;
    int weight = 0;
    for(int i =0;i<weights.size();i++){
        if(weight + weights[i] <= mid){
            weight = weight + weights[i];
        }
        else{
            daycount++;
            if(daycount>days||weights[i]>mid){
                return 0;
            }
            weight=0;
            weight=weights[i];
        }
    }
    return 1;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int e = accumulate(weights.begin(),weights.end(),0);
        int mid = s + (e-s)/2;
        int ans =-1;
        while(s<=e){
            if(isPossible(weights,days,mid)){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
             mid= s + (e-s)/2;
        }
    return ans;
}
};