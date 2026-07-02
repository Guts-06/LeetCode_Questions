class Solution {
public:
bool isPossible(vector<int>& bloomDay, int m, int k,int day){
    int count=0;
    int bouq=0;
    int n = bloomDay.size();
    for(int i =0 ; i<n ;i++){
        if(bloomDay[i]<=day){
            count++;
        }
        else{
            bouq+= (count/k);
            count=0;
        }
    }
        bouq+=(count/k);
        return bouq>=m;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int n =bloomDay.size();
        int maxi=INT_MIN;
        for(int i = 0 ; i<n;i++){
            maxi=max(maxi,bloomDay[i]);
        }
        int high=maxi;
        long long int flowers =1LL* m*k;
        if(n<flowers){
            return -1;
        }
        
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
        
    }
};