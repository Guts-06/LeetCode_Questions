class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sum2=0;
        int dig=0;
        while(n>0){
            dig=n%10;
            sum+=dig;
            sum2+=dig*dig;
            n=n/10;
        }
        if(sum2-sum>=50) return true;

        return false;
    }
};