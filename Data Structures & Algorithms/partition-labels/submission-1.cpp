class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_c;
        for (int i = 0; i < s.size(); ++i) {
            last_c[s[i]] = i;
        }

        vector<int> result;
        int target_i = 0;
        int p_size = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++p_size;
            target_i = max(target_i, last_c[s[i]]);
            if (i == target_i) {
                result.push_back(p_size);
                p_size = 0;
            }
        }

        return result;
    }
};
