class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for (size_t i = 0; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            events.push_back({start, 1});
            events.push_back({end, -1});
        }
        std::sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
            if (e1.first == e2.first) {
                return e1.second > e2.second;;
            } else {
                return e1.first < e2.first;
            }
        });

        vector<vector<int>> result;
        int active = 0;
        int start = -1;
        int i = 0;
        while (i < events.size()) {
            auto& [time, type] = events[i];
            int new_active = active;
            while (i < events.size() && time == events[i].first) {
                active += events[i].second;
                cout << events[i].first << ' ' << active << endl;
                if (start == -1 && active > 0) {
                    start = time;
                }
                ++i;
            }
            if (start != -1 && active == 0) {
                result.push_back({start, time});
                start = -1;
            }
        }

        return result;
    }
};
