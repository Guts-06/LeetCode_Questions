class Solution {
public:
int firstOcc(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int mid = (start+end)/2;
    int ans=-1;
    while(start<=end){
        if(target==nums[mid]){
            ans=mid;
            end = mid-1;
            }
        if(target<nums[mid]){
            end=mid-1;
        }
        if(target>nums[mid]){
            start = mid +1;
        }
        mid = (start + end)/2;
    }
    return ans;
}
int lastOcc(vector<int>& nums, int target){
    int start = 0;
    int end = nums.size()-1;
    int mid = (start+end)/2;
    int ans=-1;
    while(start<=end){
        if(target==nums[mid]){
            ans=mid;
            start=mid+1;
            }
        if(target<nums[mid]){
            end = mid-1;
        }
        if(target>nums[mid]){
            start = mid +1;
        }
        mid = (start + end)/2;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOcc(nums,target);
        int last=lastOcc(nums,target);
        return {first,last};

    }
};