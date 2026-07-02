class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(k>0 && st.empty()!=1 && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0){
            return "0";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};