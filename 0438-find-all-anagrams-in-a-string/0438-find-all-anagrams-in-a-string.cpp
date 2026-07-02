class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        if(m>n)
            return {} ;
        vector<int>mps(26,0);
        vector<int>mpp(26,0);
        for(char c:p){
            mpp[c-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            mps[s[i]-'a']++;
            if(mps==mpp){
                ans.push_back(0);
            }
        }
        
        
        for(int i=m;i<n;i++){
            mps[s[i]-'a']++;
            mps[s[i-m]-'a']--;
            if(mps==mpp){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};