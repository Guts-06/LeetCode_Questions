class Solution {
public:
    int backtrack(string& tiles,vector<int>&used){
        // if(index==tiles.size()){
        //     return cnt;
        // }
        int cnt=0;
        for(int i=0;i<tiles.size();i++){
            if(used[i]){
                continue;
            }
            if(i>0&&tiles[i]==tiles[i-1]&&used[i-1]!=1){
                continue;
            }
            used[i]=1;
            
            cnt+=1+backtrack(tiles,used);
            used[i]=0;

        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<int>used(tiles.size(),0);
        return backtrack(tiles,used);
        
    }
};