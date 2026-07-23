class Twitter {
public:
    int time=0;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>following;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,pair<int,int>>>pq;

        following[userId].insert(userId);

        for(int user: following[userId]){
            if(!tweets[user].empty()){
                int idx=tweets[user].size()-1;
                pq.push({tweets[user][idx].first,{user,idx}});
            }
        }
        vector<int>feed;

        while(!pq.empty() && feed.size() < 10){
            auto top=pq.top();
            pq.pop();

            int user=top.second.first;
            int idx=top.second.second;

            feed.push_back(tweets[user][idx].second);

            if(idx-1>=0){
                pq.push({tweets[user][idx-1].first,{user,idx-1}});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
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