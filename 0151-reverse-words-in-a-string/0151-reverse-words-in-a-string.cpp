class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string word="";
        vector<string>words;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else if(word.size()){
                words.push_back(word);
                word="";
            }
            
        }
        if(word.size()!=0){
            words.push_back(word);
        }

        reverse(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(i<words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};