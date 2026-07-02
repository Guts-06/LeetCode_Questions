class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int mini=INT_MAX;
        int left=0;
        int sum=0;
        int windowSize=n-k;
        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(windowSize==0) return totalSum;
        for(int right = 0; right < n; right++){

            sum += cardPoints[right];

            // maintain fixed window
            if(right - left + 1 > windowSize){
                sum -= cardPoints[left];
                left++;
            }

            // update answer only for exact window size
            if(right - left + 1 == windowSize){
                mini = min(mini, sum);
            }
        }
        
        return totalSum-mini;

    }
};