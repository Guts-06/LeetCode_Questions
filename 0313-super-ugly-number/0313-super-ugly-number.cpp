class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
     if(n==1) return 1;   
     
     int k= primes.size();
     vector<int> freq(k,0);
     long long ugly[n];
     ugly[0]=1;

     for(int i=1;i<n;i++){
        long long mini=INT_MAX;
        for(int j=0;j<k;j++){
            mini=min(mini,(long long)primes[j]*ugly[freq[j]]);}
            ugly[i]=mini;
        for(int j=0;j<k;j++){
            if(mini==primes[j]*ugly[freq[j]]) freq[j]++;
            }
        }
     
     return ugly[n-1];
    }
};