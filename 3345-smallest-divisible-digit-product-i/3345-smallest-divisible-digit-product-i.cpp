class Solution {
public:
    int prod(int n){
        int prod=1;
        while(n){
            prod*=n%10;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        if(n==100){
            return 100;
        }
        if(t==1){
            return n;
        }
        while(prod(n)%t!=0){
            n++;
        }
        return n;

        
    }
};