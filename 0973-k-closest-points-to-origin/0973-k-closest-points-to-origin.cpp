class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        priority_queue<vector<int>> pq;

        for(auto it:points){
            int x=it[0];
            int y=it[1];
            pq.push({x*x+y*y,x,y});
            if(pq.size()>k){
                pq.pop();
            }

        }
        for(int i=0;i<k;i++){
            ans[i]={pq.top()[1],pq.top()[2]};
            pq.pop();
        }
        return ans;
        
    }
};