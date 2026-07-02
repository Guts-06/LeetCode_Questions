class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        unordered_map<string,int> mp;

        // store all prefixes
        for(string s : strs) {

            string temp = "";

            for(char ch : s) {

                temp += ch;
                mp[temp]++;
            }
        }

        string ans = "";

        for(auto it : mp) {

            // common in all strings
            if(it.second == strs.size()) {

                if(it.first.size() > ans.size()) {
                    ans = it.first;
                }
            }
        }

        return ans;
    }
};