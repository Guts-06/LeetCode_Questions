class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int>st;
        for(int x:asteroids){
            if(x>0) st.push(x);
            else{
                bool destroyed=false;
                while(!st.empty()&&st.top()>0&& x<0){
                    if(st.top()<abs(x)){
                        st.pop();
                    }
                    else if(st.top()>abs(x)){
                        destroyed=true;
                        break;
                    }
                    else{
                        st.pop();
                        destroyed=true;
                        break;
                    }
                }
                if(destroyed==false){
                    st.push(x);
                }
            }
            
        }
        int n=st.size();
        for(int i=0;i<n;i++){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());

            return ans;
        }
};