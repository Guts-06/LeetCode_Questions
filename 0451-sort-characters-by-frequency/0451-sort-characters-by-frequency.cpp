class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        priority_queue<pair<int,char>>pq;
        for(char x:s){
            mp[x]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(pq.size()!=0){
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans+=string(freq,ch);
        }
        return ans;
    }
};