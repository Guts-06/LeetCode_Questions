class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> arr ;
        for(int x: nums){
        string s = to_string(x);
        for(char c: s){
            arr.push_back(c-'0');
        }
    }
        return arr;
    }
};