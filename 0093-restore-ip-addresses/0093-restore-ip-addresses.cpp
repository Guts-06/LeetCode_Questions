class Solution {
public:
    void backtrack(int ind,int count,string &temp,vector<string>&ans,string s){
        int remainingDigits = s.size() - ind;
        int remainingParts = 4 - count;

        if (remainingDigits < remainingParts || remainingDigits > remainingParts * 3)
            return;
        if(count==4){
            if(ind==s.size()){
                temp.pop_back();
                ans.push_back(temp);
            }
            return;
        }
        string a;
        for(int i=ind;i<min(ind+3,(int)s.size());i++){
            a+=s[i];
            if(a.size()>1 && a[0]=='0') break;
            int size=temp.size();
            int n=stoi(a);
            if(n>255) break;
            temp+=a;
            temp.push_back('.');
            backtrack(i+1,count+1,temp,ans,s);
            temp.resize(size);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return {};
        vector<string>ans;
        string temp;
        int count=0;
        backtrack(0,count,temp,ans,s);
        return ans;
    }
};