class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=rows-1;
        int col=0;
        while(row>=0 && col<cols){
            int node=matrix[row][col];
            if(node==target){
                return true;
            }
            else if(node<target){
                col++;
            }
            else if(node>target){
                row--;
            }
        }
        return false;
    }
};