class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> nega;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n;i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else{nega.push_back(nums[i]);

            }
        }
        for(int i=0; i<n/2;i++){
            ans.push_back(positive[i]);
            ans.push_back(nega[i]);
        }

        return ans;
        //TC--->O(n)
        //SC--->O(n)
    }
};