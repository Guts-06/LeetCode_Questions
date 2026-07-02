class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int x:nums){
            mp[x]++;
        }

        for(auto &it:mp){
            int element=it.first;
            int freq=it.second;
            pair<int,int>current={freq,element};
            
            if(pq.size()<k){
                pq.push(current);
                continue;
            }
            if(pq.top().first>freq){
                continue;
            }
            pq.pop();
            pq.push(current);
        }
        vector<int> ans;
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};