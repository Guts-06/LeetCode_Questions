class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(auto it:s){
            if(it=='('){
                if(cnt>0)ans+=it;
                cnt++;
            }
            else{
                cnt--;
             if(cnt>0)ans+=it;
            }
        }
        return ans;
    }
};