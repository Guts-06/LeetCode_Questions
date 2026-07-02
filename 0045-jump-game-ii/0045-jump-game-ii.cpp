class Solution {
public:
    int jump(vector<int>& nums) {
        int right=0;
        int left=0;
        int jump=0;

        while(right<nums.size()-1){
            int furthest=0;
            for(int i=left;i<=right;i++){
                furthest=max(furthest,nums[i]+i);
            }
            left=right+1;
            right=furthest;
            jump++;
        }
        return jump;
    }
};