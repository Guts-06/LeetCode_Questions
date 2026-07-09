class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                mp[it].push_back(i);
            }
        }
        queue<int>q;
        vector<int> vis(routes.size(),0);
        q.push(source);
        int buses=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int stop=q.front();
                q.pop();
                if(stop==target) return buses;
                for(int i:mp[stop]){
                    if(vis[i])continue;
                    vis[i]=1;
                    for(auto nextStop:routes[i]){
                        q.push(nextStop);
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};