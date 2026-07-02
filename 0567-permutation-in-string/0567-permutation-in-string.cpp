class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(n>m)
            return false;
        
        vector<int>mps1(26,0);
        vector<int>mps2(26,0);

        for(char c:s1){
            mps1[c-'a']++;
        }

        for(int i=0;i<n;i++){
            mps2[s2[i]-'a']++;
        }

        if(mps1==mps2)
            return true;
        
        for(int i=n;i<m;i++){
            mps2[s2[i]-'a']++;
            mps2[s2[i-n]-'a']--;
            if(mps1==mps2)
                return true;
        }
        return false;
    }
};