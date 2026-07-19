class Solution {
public:
    string removeDuplicateLetters(string s) {
         vector<int>freq(26,0);
       vector<bool>vis(26,false);

       for(auto &it:s){
            freq[it-'a']++;
       }
       string ans;
       for(auto &it:s){
        freq[it-'a']--;
        if(vis[it-'a']) continue;
        while(ans.size()!=0 && ans.back()>it && freq[ans.back()-'a']>0){
            vis[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans+=it;
        vis[it-'a']=true;
       }
       return ans;
    }
};