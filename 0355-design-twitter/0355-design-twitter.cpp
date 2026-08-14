class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followings;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;

        followings[userId].insert(userId);

        for(auto x : followings[userId]){
            if(!tweets[x].empty()){
                int i = tweets[x].size() - 1;
                pq.push({tweets[x][i].first, x, i});
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10){
            auto [t, u, i] = pq.top();
            pq.pop();

            ans.push_back(tweets[u][i].second);

            if(i > 0){
                i--;
                pq.push({tweets[u][i].first, u, i});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followings[followerId].erase(followeeId);
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