class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell=0;
        int buy=INT_MIN;
        // bool can=true;
        for(int i=0;i<prices.size();i++){
            buy=max(buy,sell-prices[i]);
            sell=max(sell,prices[i]+buy-fee);
            }
        
        return sell;
    }
};