class Solution {
public:
    long long nextGreaterElement(int n) {
        string s=to_string(n);
        int f=s.size();
        int i=f-2;
        if(n==INT_MAX) return -1;
        while(i>=0 && s[i]>=s[i+1]){
            i--;
        }
        if(i<0) return -1;
        int j=f-1;
        while(s[i]>=s[j]){
            j--;
        }

        swap ( s[i],s[j]);

        reverse(s.begin()+i+1,s.end());

        long long ans= stoll(s);
        
         if(ans > INT_MAX) return -1;

        return ans;
    }
};