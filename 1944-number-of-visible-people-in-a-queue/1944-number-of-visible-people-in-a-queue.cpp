class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        //NGE wala concept hi hai w a counter
        vector<int> ans(heights.size());
        stack<int> st;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty() && heights[i]>=st.top()){
                cnt++;
                st.pop();
            }
            if(!st.empty()) cnt++; // apne aage wala
            ans[i]=cnt;

            st.push(heights[i]);
        }
        return ans;
    }
};