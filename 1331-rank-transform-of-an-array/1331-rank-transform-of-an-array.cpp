class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return {};
       vector<int>a=arr;
       unordered_map<int,int>mp;
       sort(a.begin(),a.end());
       mp[a[0]]=1;
       for(int i=1;i<a.size();i++){
            if(mp.find(a[i])!=mp.end()){
                continue;
            }
            mp[a[i]]=mp[a[i-1]]+1;
       }
       for(int i=0;i<arr.size();i++){
        arr[i]=mp[arr[i]];
       }
      return arr;
    }
};