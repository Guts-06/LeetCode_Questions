class Solution {
public:
    string simplifyPath(string path) {
        deque<string>st;
        int n=path.size();
        int i=0;
        while(i<n){
            string word="";
            if(path[i]=='/'){
                i++;
                continue;
            }
    
            while(i<n && path[i]!='/'){
                word+=path[i];
                i++;
                
            }
            
            
            if(word.size()==0||word==".")continue;
            else if(word==".."){
                if(!st.empty()){st.pop_back();}}
            else{
                st.push_back(word);
            }
        }
        string ans="";
        while(!st.empty()){
            string temp=st.front();
            st.pop_front();
            ans+="/"+temp;
        }
        return ans.empty() ?"/":ans;
    }
};