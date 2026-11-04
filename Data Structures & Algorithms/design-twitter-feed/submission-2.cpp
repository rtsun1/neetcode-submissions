class Twitter {
public:
    Twitter() {
        for (int i = 0; i < 501; ++i) {
            follow(i, i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({age++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> feed;
        for (int followee : following[userId]) {
            for (int i = 0; i < 10; ++i) {
                if (i >= tweets[followee].size()) {
                    break;
                }
                pair<int, int> tweet = tweets[followee][tweets[followee].size() - i - 1];
                feed.push(tweet);
                if (feed.size() > 10) {
                    feed.pop();
                }
            }
        }

        vector<int> result;
        result.resize(feed.size());
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = feed.top().second;
            feed.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    int age = 0;
    vector<vector<pair<int, int>>> tweets{501};
    vector<unordered_set<int>> following{501};
};
