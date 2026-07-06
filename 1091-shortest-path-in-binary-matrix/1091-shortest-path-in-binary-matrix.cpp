class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1; // Mark as visited in-place

        int dirs[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int r = curr.first.first, c = curr.first.second, d = curr.second;

            if (r == n - 1 && c == n - 1) return d;

            for (auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; 
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return -1;
    }
};