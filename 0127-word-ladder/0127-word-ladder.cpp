class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,count]=q.front();
            q.pop();

            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,count+1});
                    }
                }
                word[i]=org;
            }
            if(word==endWord) return count;
        }
        return 0;
    }
};