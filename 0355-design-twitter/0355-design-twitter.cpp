class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>mp1;
    unordered_map<int,unordered_set<int>>mp2;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp1[userId].push_back({tweetId,time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp=[&](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);

        for(auto &it:mp2[userId]){
            for(auto &jt:mp1[it]){
                pq.push(jt);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
        for(auto tweet:mp1[userId]){
            pq.push(tweet);
            if(pq.size()>10)pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            int a=pq.top().first;
            pq.pop();
            ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp2[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp2[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */