class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> ans(isWater.size(),
                                vector<int>(isWater[0].size(), -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            vector<vector<int>> dis = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}
            };

            for (int k = 0; k < 4; k++) {
                int newi = i + dis[k][0];
                int newj = j + dis[k][1];

                if (newi >= 0 && newi < isWater.size() &&
                    newj >= 0 && newj < isWater[0].size() &&
                    ans[newi][newj] == -1) {

                    ans[newi][newj] = ans[i][j] + 1;
                    q.push({newi, newj});
                }
            }
        }

        return ans;
    }
};