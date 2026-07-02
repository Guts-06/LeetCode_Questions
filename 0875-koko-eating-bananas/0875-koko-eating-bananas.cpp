class Solution {
public:
int maxElement(vector<int>& piles){
    int maxi=INT_MIN;
    int n = piles.size();
    for(int i =0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long int totalHours(vector<int>& piles, int k){
    long long int total_hours=0;
    for(int i = 0;i<piles.size();i++){
        total_hours+=ceil((double)piles[i]/(double)k);
    }
    return total_hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxElement(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            long long int total_hours=totalHours(piles,mid);
            if(total_hours<=h){
                high=mid-1;
                
            }
            else{
                low=mid+1;
                
            }

        }
        return low;
    }
};