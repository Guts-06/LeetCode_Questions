class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int freq=0;
        for(char c:tasks){
            mp[c]++;
            freq=max(mp[c],freq);
        }
        int ans=(freq-1)*(n+1);
        for(auto it :mp){
            if(it.second==freq){
                ans++;
            }
        }
        return max((int)tasks.size(),ans);
    }
};