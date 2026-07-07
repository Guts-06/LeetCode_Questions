class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string t;
        if(n==0) return 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                t=t+s[i];
            }
        }
        int sum=0;
        for(char c:t){
            sum+=c-'0';
        }
        int x=stoi(t);
        return (long long)sum*x;
    }
};