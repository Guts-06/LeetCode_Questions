class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int mid ){
        int count=1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]+ sum <=mid){
                    sum=sum + nums[i];
            }
            else{
                count++;
                if(count>k||nums[i]>mid){
                    return false;
                }
                sum = 0;
                sum = nums[i];
            }


        }

        return true;

    }
    int splitArray(vector<int>& nums, int k) {
        int s =0;
        int e= accumulate(nums.begin(),nums.end(),0);
        int mid= s + (e-s)/2;
        int ans=-1;
        while(s<=e){
            if(isPossible(nums,k,mid)){
                e = mid-1;
                ans = mid;
            }
            else{
                s=mid +1;
            }
             mid= s + (e-s)/2;
        }
        return ans;
    }
};