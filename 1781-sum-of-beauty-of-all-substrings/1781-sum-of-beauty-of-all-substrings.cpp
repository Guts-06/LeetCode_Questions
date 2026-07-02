class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int frequencyMap[26]={0};

            for(int j=i;j<s.size();j++){
                frequencyMap[s[j]-'a']++;
                int maxFreq=INT_MIN;
                int minFreq=INT_MAX;
                for(int k=0;k<26;k++){
                    if(frequencyMap[k]>0){
                    maxFreq=max(maxFreq,frequencyMap[k]);
                    minFreq=min(minFreq,frequencyMap[k]);
                    }
                }
                ans+=(maxFreq-minFreq);
            }
            
        }
        return ans;
    }
};