class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        int checkrow[] = {0, -1, 0, 1};
        int checkcol[] = {-1, 0, 1, 0};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + checkrow[i];
                int nc = col + checkcol[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    mat[nr][nc] > mat[row][col] + 1) {
                    mat[nr][nc] = mat[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};