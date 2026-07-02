class Solution {
public:
    vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,int index,vector<string>&ans,string temp){
        if(index==digits.length()){
            ans.push_back(temp);
            return;
        }
        string letters=mp[digits[index]-'0'];
        for(int i=0;i<letters.size();i++){
            temp.push_back(letters[i]);
            solve(digits,index+1,ans,temp);
            temp.pop_back();
        }
        

    }
    vector<string> letterCombinations(string digits) {
        string temp;
        if(digits.length()==0)
            return {};
        vector<string>ans;
        solve(digits,0,ans,temp);
        return ans;
    }
};