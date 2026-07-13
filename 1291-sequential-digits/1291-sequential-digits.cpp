class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        string lows=to_string(low);
        string highs=to_string(high);
        int cnt1=lows.size();
        int cnt2=highs.size();
        vector<int> ans;
        for(int i=cnt1;i<=cnt2;i++){
            for(int j=0;j<=9-i;j++){
                string n=s.substr(j,i);
                int num=stoi(n);
                if(num>=low&&num<=high){
                    ans.push_back(num);
                }
            }
        }
        
        return ans;

    }
};