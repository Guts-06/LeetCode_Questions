class Solution {
public:
    int mirrorDistance(int n) {
        int k=n;
        int ans=0;
        while(n>0){
            ans=ans*10 + n%10;
            n/=10;
        }
        return abs(ans-k);
    }
};