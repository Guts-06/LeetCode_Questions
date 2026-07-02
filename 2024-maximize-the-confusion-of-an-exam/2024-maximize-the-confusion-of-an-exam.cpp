class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int left=0;
        int ans=0;
        int cnt1=0; int cnt2=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T'){
                cnt1++;
            }
            else{
                cnt2++;
            }
            while(cnt1>k && cnt2>k){
                if(answerKey[left]=='T'){
                    cnt1--;
                }
                else{
                    cnt2--;
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;

    }
};