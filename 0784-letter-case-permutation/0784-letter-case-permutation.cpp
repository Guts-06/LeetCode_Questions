class Solution {
public:
    void solve(int ind,string &temp,vector<string>&ans,string s){
        if(temp.size()==s.size()){
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[ind])){
            temp.push_back(s[ind]);
            solve(ind+1,temp,ans,s);
            temp.pop_back();
        }
        else{
            
            temp.push_back(tolower(s[ind]));
            solve(ind+1,temp,ans,s);
            temp.pop_back();
            
            temp.push_back(toupper(s[ind]));
            solve(ind+1,temp,ans,s);
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp;
        solve(0,temp,ans,s);
        return ans;
    }
};