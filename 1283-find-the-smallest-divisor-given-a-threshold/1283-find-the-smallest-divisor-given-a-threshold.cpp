class Solution {
public:
int totalsum(vector<int>& nums, int threshold){
    int sums=0;
    for(int i=0;i<nums.size();i++){
        sums+=ceil((double)nums[i]/(double)threshold);
    }
    return sums;
}
int maxelement(vector<int>& nums){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        maxi=max(nums[i],maxi);
    }
    return maxi;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= maxelement(nums);

        while(low<=high){
            int mid=(low+high)/2;
            int sum=totalsum(nums,mid);
            if(sum<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};