class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        const int mod = 1e9 + 7;

        vector<long long> time2reach(n, LLONG_MAX);
        vector<int> ways2reach(n, 0);

        time2reach[0] = 0;
        ways2reach[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time > time2reach[node])
                continue;

            for (auto [adjnode, wt] : adj[node]) {

                if (time + wt < time2reach[adjnode]) {

                    time2reach[adjnode] = time + wt;
                    ways2reach[adjnode] = ways2reach[node];

                    pq.push({time2reach[adjnode], adjnode});
                }
                else if (time + wt == time2reach[adjnode]) {

                    ways2reach[adjnode] =
                        (ways2reach[adjnode] + ways2reach[node]) % mod;
                }
            }
        }

        return ways2reach[n - 1];
    }
};
