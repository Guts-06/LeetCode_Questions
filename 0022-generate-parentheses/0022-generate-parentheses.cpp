class Solution {
public:
vector<string> ans;
    void solve(int n,int openbracket,int closingbracket,string temp){
        
        if(openbracket==n&&closingbracket==n){
            ans.push_back(temp);
            return;
        }
        if(openbracket<n){
            solve(n,openbracket+1,closingbracket,temp+'(');

        }
        if(closingbracket<openbracket){
            solve(n,openbracket,closingbracket+1,temp+')');

        }
        // temp.pop_back();
        // solve(n,openbracket,closingbracket,temp);

    }
    vector<string> generateParenthesis(int n) {
        // vector<string>ans;
        string temp;
        solve(n,0,0,temp);
        return ans;
    }
};