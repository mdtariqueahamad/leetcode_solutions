class Twitter {
    vector<int> posts;
    unordered_map<int, vector<int>> user_tweet;
    unordered_map<int, unordered_set<int>> user_foll;
public:
    Twitter() { }
    
    void postTweet(int userId, int tweetId) {
        user_tweet[userId].push_back(posts.size());
        posts.push_back(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int, int>> pq;

            unordered_set<int> users = user_foll[userId];
            users.insert(userId);

            for (int u : users) {
                if (!user_tweet[u].empty()) {
                    int idx = user_tweet[u].back();
                    pq.push({idx, u});
                }
            }

            vector<int> feed;

            while (!pq.empty() && feed.size() < 10) {
                auto [idx, u] = pq.top();
                pq.pop();

                feed.push_back(posts[idx]);

                auto& tweets = user_tweet[u];
                auto it = lower_bound(tweets.begin(), tweets.end(), idx);

                if (it != tweets.begin()) {
                    --it;
                    pq.push({*it, u});
                }
            }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        
        if(followerId == followeeId) return;

        user_foll[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_foll[followerId].erase(followeeId);
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
