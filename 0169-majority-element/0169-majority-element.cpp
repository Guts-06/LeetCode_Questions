class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int n= nums.size();
        int count = 0;
        for(int i =0 ; i<n;i++){
            if(count==0){
                element=nums[i];
                count=1;
            }
            else{
                 if(nums[i]==element){
                count++;
                }
                else{
                count--;
                }
            }
        }
        int count1=0;
        for(int i =0 ; i<n;i++){
            if(element==nums[i]){
                count1++;
            }
        }
        if(count1>n/2){
            return element;
        }
        else{
            return -1;
        }
    }
};