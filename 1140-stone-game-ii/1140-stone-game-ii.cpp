class Solution {
public:

    int f(bool turn, int i, vector<int>& piles, int m,
          int dp[2][101][101]) {

        if (i >= piles.size())
            return 0;

        if (dp[turn][i][m] != -1)
            return dp[turn][i][m];

        int ans = turn ? -1 : 1e7;

        int stones = 0;

        int end = min(2 * m, (int)piles.size() - i);

        for (int x = 1; x <= end; x++) {

            stones += piles[i + x - 1];

            if (turn) {
                // Alice → maximize her stones
                ans = max(ans,
                    stones + f(false, i + x, piles,
                               max(m, x), dp));
            }
            else {
                // Bob → minimize Alice's stones
                ans = min(ans,
                    f(true, i + x, piles,
                      max(m, x), dp));
            }
        }

        return dp[turn][i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int dp[2][101][101];

        memset(dp, -1, sizeof(dp));

        return f(true, 0, piles, 1, dp);
    }
};