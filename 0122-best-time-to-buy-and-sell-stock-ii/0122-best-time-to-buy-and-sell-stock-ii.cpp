class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n-1;i++){
            int sale=0;
            
                if(prices[i+1]>prices[i]){
                    sale=prices[i+1]-prices[i];
                }
            
            profit+=sale;
        }
        return profit;
    }
};