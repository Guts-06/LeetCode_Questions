class Solution {
public:
    long long mod=1e9+7;
    long long power(long long base,long long exp){
        if(exp==0){
            return 1;
        }
        long long half=power(base,exp/2);
        half=(half*half)%mod;

        if(exp%2){
            half=half*base%mod;
        }
        return half;
        
    }
    long long countGoodNumbers(long long n) {
        return (power(5,(n+1)/2)%mod*power(4,n/2)%mod)%mod;
    }
};