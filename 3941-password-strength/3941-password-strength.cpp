class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        for(char x :password){
            st.insert(x);
        }
        int ans=0;
        for(char c:st){
            if(c>='a' && c<='z'){
                ans +=1;
            }
            else if(c>='A'&&c<='Z'){
                ans+=2;
            }
            else if(c>='0'&&c<='9'){
                ans+=3;
            }
            else if(c=='!' || c=='@' ||c=='#' ||c=='$'){
                ans+=5;
            }
    }
    return ans;
    }
};