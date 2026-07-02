class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        // set<int> div;
        int n=nums.size();
        for(int i=0; i<n;i++){
            int sq=sqrt(nums[i]);
            set<int> div;
            for(int j=1;j<=sq;j++){
                if(nums[i]%j==0){
                    div.insert(j);
                    div.insert(nums[i]);
                    div.insert(nums[i]/j);
                }
            }
            if(div.size()==4){
                ans += accumulate(div.begin(),div.end(),0);
            }
        }
        return ans;
    }
};