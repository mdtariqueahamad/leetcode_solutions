class Twitter {
    int timer = 0;

    // user -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        // Own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Followed users' tweets
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};