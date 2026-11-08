class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> s_count;
        unordered_map<char, int> p_count;
        for (char c : s) {
            ++s_count[c];
        }

        vector<int> result;
        int p_size = 0;
        for (char c : s) {
            ++p_count[c];
            ++p_size;
            bool partition_done = true;
            for (const auto [c, freq] : p_count) {
                if (s_count[c] != freq) {
                    partition_done = false;
                }
            }
            if (partition_done) {
                result.push_back(p_size);
                p_count.clear();
                p_size = 0;
            }
        }

        return result;
    }
};
