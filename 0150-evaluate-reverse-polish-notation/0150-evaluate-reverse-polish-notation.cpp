class Solution {
public:
    int operation(int a,int b,string o){
        if(o=="+"){
            return a+b;
        }
        if(o=="-"){
            return a-b;
        }
        if(o=="*"){
            return a*b;

        }
        if(o=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it=="+"||it=="-"||it=="*"||it=="/"){
                int b=(st.top());
                st.pop();
                int a=(st.top());
                st.pop();
                int result=operation(a,b,it);
                st.push(result);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};