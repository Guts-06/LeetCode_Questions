class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int i=1;
        long long sum_odd=0;
        long long sum_even=0;
        while(n>0){
            sum_even+=2*i;
            sum_odd+=2*i-1;
            i++;
            n--;
        }
        return gcd(sum_even,sum_odd);
    }
};