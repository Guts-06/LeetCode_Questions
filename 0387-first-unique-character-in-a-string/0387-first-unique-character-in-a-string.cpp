class Solution {
public:
    int firstUniqChar(string s) {
         // Fixed-size lookup bucket for lowercase English characters
        vector<int> freq(26, 0);

        // First Pass: Aggregate frequency weights for each letter
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Second Pass: Find the first index pointing to an element with a frequency count of 1
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};