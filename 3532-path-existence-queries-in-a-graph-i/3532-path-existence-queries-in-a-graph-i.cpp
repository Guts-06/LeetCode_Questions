class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> compare(n, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                compare[i] = compare[i - 1];
            } else {
                compare[i] = compare[i - 1]+1;
            }
        }
        vector<bool> ans;
        for (auto it : queries) {
            ans.push_back(compare[it[0]] == compare[it[1]]);
        }
        return ans;
    }
};