class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(char c:s){
            mp[c]++;
        }
        for(auto &it:mp){
            int freq=it.second;
            char ch=it.first;
            pq.push({freq,ch});
        }
        string ans;
        while(pq.size()>=2){
            auto [freq1,ch1]=pq.top();
            pq.pop();
            auto [freq2,ch2]=pq.top();
            pq.pop();
            ans+=ch1;
            ans+=ch2;
            
            freq1--;
            freq2--;
            if(freq1>0) pq.push({freq1,ch1});
            if(freq2>0) pq.push({freq2,ch2});
        }
        if(pq.size()!=0){
            auto[freq,ch]=pq.top();
            if(freq>1) return "";
            ans+=ch;
        }
        return ans;
    }
};