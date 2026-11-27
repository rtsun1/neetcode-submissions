#include <climits>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool even_med = (nums1.size() + nums2.size()) % 2 == 0;
        int target_before = even_med
            ? (nums1.size() + nums2.size()) / 2 - 1
            : (nums1.size() + nums2.size()) / 2;

        int l1 = max(-1, target_before - static_cast<int>(nums2.size()));
        int r1 = min(static_cast<int>(nums1.size()) - 1, target_before);

        int i1, i2;
        int left1, left2, right1, right2;

        while (r1 >= l1) {
            i1 = l1 + ((r1 - l1) / 2);
            i2 = target_before - i1 - 1;

            left1 = i1 >= 0
                ? nums1[i1]
                : INT_MIN;
            left2 = i2 >= 0
                ? nums2[i2]
                : INT_MIN;
            right1 = i1 + 1 < nums1.size()
                ? nums1[i1 + 1]
                : INT_MAX;
            right2 = i2 + 1 < nums2.size()
                ? nums2[i2 + 1]
                : INT_MAX;

            if (left2 > right1) {
                l1 = i1 + 1;
            } else if (max(left1, left2) <= min(right1, right2)) {
                break;
            } else {
                r1 = i1 - 1;
            }
        }

        if (even_med) {
            return (static_cast<double>(max(left1, left2))
                    + min(right1, right2)) / 2;
        } else {
            return max(left1, left2);
        }
    }
};