class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count=0;
        while(n>0){
            if((n&3)==3){
                count++;
            }
            n=n>>1;
        }
        if(count==1){
            return true;
        }
        return false;
    }
};