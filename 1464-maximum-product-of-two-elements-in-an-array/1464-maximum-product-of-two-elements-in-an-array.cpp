class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=1;
        int max2=1;
        for(auto it:nums){
            if(max1<=it){
                max2=max1;
                max1=it;

            }
            else if(max2<=it){
                max2=it;
            }
        }
        return (max1-1)*(max2-1);
    }
};