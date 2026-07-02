class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>>merge;

        for(auto it:occupiedIntervals){
            int start=it[0];
            int end=it[1];
            if(merge.empty()||start>merge.back()[1]+1){
                merge.push_back(it);
            }
            else{
                merge.back()[1]=max(merge.back()[1],end);
            }
        }
        vector<vector<int>>ans;
        for(auto it:merge){
            if(it[1]<freeStart||it[0]>freeEnd){
                ans.push_back(it);
                continue;
            }
            if(it[0]<freeStart){
                ans.push_back({it[0],freeStart-1});
            }
            if(it[1]>freeEnd){
                ans.push_back({freeEnd+1,it[1]});
            }
        }
        return ans;
    }
};