class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;

        for(char c:t){need[c]++;}
        int needcount=need.size();
        int havecount=0;
        int minlength=INT_MAX;
        int left=0;
        int start=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;

            if(need.count(c) && need[c]==window[c]){
                havecount++;

            }
            while(havecount==needcount){

                if(right-left+1<minlength){
                    minlength=right-left+1;
                    start=left;
                }

                char ch=s[left];
                window[ch]--;

                if(need.count(ch)&&window[ch]<need[ch] ){
                    havecount--;
                }
                left++;
            }
        }
        if(minlength==INT_MAX){
            return "";
        }

        return s.substr(start,minlength);

    }
};