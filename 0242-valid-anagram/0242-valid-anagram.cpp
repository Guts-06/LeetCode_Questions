class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        if(s.size()!=t.size()){
            return false;
        }
        for(char c:s){
            mp1[c]++;
        }
        int n=t.size();
        for(int i=0;i<n;i++){
            if(mp1.find(t[i])!=mp1.end()){
                mp1[t[i]]--;
            }
            if(mp1[t[i]]==0){
                mp1.erase(t[i]);
            }
        }
        if(mp1.size()==0){
            return true;
        }
        return false;
    }
};