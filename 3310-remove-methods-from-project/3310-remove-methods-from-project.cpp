class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, it, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(i);
        }
        vector<int> vis(n, 0);
        dfs(adj, k, vis);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (auto jt : adj[i]) {
                    if (vis[jt]) {
                        return ans;
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                res.push_back(i);
        }
        return res;
       
    }
};