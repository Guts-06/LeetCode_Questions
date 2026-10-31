class Solution {
public:
    int MOD=1e9+7;
    int f(int i, int j, bool choice,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j][choice] != -1)
            return dp[i][j][choice]%MOD;

        int down = 0, right = 0;

        if (grid[i][j] == 1) {
            if (choice == 0) {
                down = f(i + 1, j, 1, grid, dp);
            } else {
                right = f(i, j + 1, 0, grid, dp);
            }
        } else {
            down = f(i + 1, j, 1, grid, dp);
            right = f(i, j + 1, 0, grid, dp);
        }

        return dp[i][j][choice] = (down + right)%MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return f(0, 0, 0, grid, dp);
    }
};