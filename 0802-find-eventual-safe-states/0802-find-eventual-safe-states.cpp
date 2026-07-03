class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>outdeg(graph.size(),0);
        vector<int>vis(graph.size(),0);
        vector<vector<int>>rev(graph.size());
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            outdeg[i]=graph[i].size();
            for(auto it:graph[i]){
                rev[it].push_back(i);
            }
        }
        queue<int>q;
        for (int i = 0; i < graph.size(); i++) {
            if (outdeg[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:rev[node]){
                outdeg[it]--;
                if(outdeg[it]==0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};