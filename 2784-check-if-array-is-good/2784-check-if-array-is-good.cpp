class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        if (nums.size() != n + 1)
            return false;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (i == nums.size() - 1) {

                if (mp[i] != 2)
                    return false;
            } else {

                if (mp[i] != 1)
                    return false;
            }
        }

        return true;
    }
};