class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int length = 0;
        unordered_map<int, int> freq;
        for (right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // freq[right]++;
            length = max(length, right - left + 1);
        }
        return length;
    }
};