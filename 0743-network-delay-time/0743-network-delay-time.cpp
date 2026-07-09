class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>time(n+1,1e6);
        time[0]=0;
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto[sigTime,node]=pq.top();
            pq.pop();
            if(sigTime>time[node]){
                continue;
            }
            for(auto it:adj[node]){
                int v=it.first;
                int time2=it.second;
                if(time[v]>time2+sigTime){
                    time[v]=time2+sigTime;
                    pq.push({time[v],v});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
            if(time[i]==1e6) return -1;
            ans=max(ans,time[i]);
        }
        
        return ans;
        
    }
};