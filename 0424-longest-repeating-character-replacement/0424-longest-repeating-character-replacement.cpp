class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        vector<int>freq(26,0);
        int maxfreq=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);

            if((r-left+1) -maxfreq >k){
                freq[s[left]-'A']--;
                left++;
            }
        }
        int ans=(int)s.size()-left;
        return ans;
    }
};