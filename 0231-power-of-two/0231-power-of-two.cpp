class Solution {
public:
    bool isPowerOfTwo(int n) {
        int long long ans=1;
        for(int i=0;i<31;i++){
            
            if(ans==n){
                return true;
            }
            ans=ans*2;
        }
        return 0;
    }
};