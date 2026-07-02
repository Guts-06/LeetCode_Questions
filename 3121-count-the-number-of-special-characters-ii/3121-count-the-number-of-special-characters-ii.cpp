class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        vector<int>mpl(26,-1);
        vector<int>mpu(26,-1);
        for(char x : word){
            if(islower(x)){
                mpl[x-'a']=cnt;
            }
            else{
                if(mpu[x-'A']!=-1) continue;
                mpu[x-'A']=cnt;
            }
            cnt++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if((mpl[i]!=-1&&mpu[i]!=-1) && (mpl[i]<mpu[i])) ans++;

        }
        return ans;
        
    }
};