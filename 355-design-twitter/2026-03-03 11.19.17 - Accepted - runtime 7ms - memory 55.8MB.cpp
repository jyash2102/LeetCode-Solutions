class Twitter {
public:
    unordered_map<int,unordered_set<int>> mpp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int cnt=1;
    Twitter() {
        mpp.clear();
        cnt=1;
        tweets.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        for (auto& t : tweets[userId]) {
            pq.push(t);
            if (pq.size() > 10)
                pq.pop();
        }
        for (int followee : mpp[userId]) {
            for (auto& t : tweets[followee]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId) mpp[followerId].erase(followeeId);
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