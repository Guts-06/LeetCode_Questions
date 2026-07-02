
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid= (high+low)/2;

        while (low <= high) {
             int mid = (low + high) / 2; 

            if (nums[mid] == target) {
                return true;
            }
            if(nums[mid]==nums[low]&&nums[mid]==nums[high]){
                high--;
                low++;
                continue;
            }

            // Left half is sorted
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
                 
                 
            }
        }

        return false;  
        
    }
};
