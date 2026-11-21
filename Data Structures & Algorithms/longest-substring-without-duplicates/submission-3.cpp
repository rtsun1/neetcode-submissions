class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;
        unordered_map<char, int> taken;
        int suff_start = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto pos = taken.find(s[i]);
            if (pos != taken.end() && pos->second >= suff_start) {
                suff_start = taken[s[i]] + 1;
            }
            taken[s[i]] = i;
            best = max(best, i - suff_start + 1);
            // cout << best << ' ' << suff_start << endl;
        }
        return best;
    }

};