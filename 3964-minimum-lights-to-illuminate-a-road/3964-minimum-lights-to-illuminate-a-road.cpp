class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();

        vector<bool>visible(n);
        vector<int> diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int l=max(0,i-lights[i]);
                int r=min(n-1,i+lights[i]);

                diff[l]++;
                if(r+1<n){
                    diff[r+1]--;
                }
            }
        }
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(curr>0){
                visible[i]=true;
            }
        }
        int count=0;
        int i=0;

        while(i<n){
            if(visible[i]){
                i++;
                continue;
            }
            int j=i;
            while(j<n&&!visible[j]){
                j++;
                
            }
            int length=j-i;
            count+=(length+2)/3;
            i=j;
        }
        return count;
    }
};