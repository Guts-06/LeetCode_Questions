class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum1=0;
        int sum2=0;
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum1+=i;
            sum2+=arr[i];
            if(sum1!=sum2){
                cnt++;
            }
        }
        return n-cnt;
    }
};