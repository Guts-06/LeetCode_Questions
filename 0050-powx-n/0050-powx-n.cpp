class Solution {
public:
    double myPow(double x, int n) {
        if(n==1) return x;
        if(n==0) return 1.0;
        if (x==1.0) return 1.0;
        if(n==INT_MIN){
            return myPow(x*x,n/2);

        }
        if(n<0){
            return (1.0/myPow(x,-1*n));
        }

        if(n%2==0){
            return myPow(x*x,n/2);
        }
        else{
            return x*myPow(x,n-1);
        }
    }
};
    