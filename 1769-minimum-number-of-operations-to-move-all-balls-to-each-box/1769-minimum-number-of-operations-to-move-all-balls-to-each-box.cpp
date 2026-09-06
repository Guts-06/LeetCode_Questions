class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int cnt1=0;
        if(boxes[0]=='1')cnt1++;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+cnt1;
            if(boxes[i]=='1'){
                cnt1++;
                

            }
        }
        cnt1=0;
        if(boxes[n-1]=='1')cnt1++;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+cnt1;
            if(boxes[i]=='1'){
                cnt1++;
                
                
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] = pre[i] + suf[i];
        }

        return ans;
    }
};