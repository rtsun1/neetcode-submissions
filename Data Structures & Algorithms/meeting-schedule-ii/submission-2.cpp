/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<Interval> starts(intervals);
        vector<Interval> ends(intervals);
        sort(starts.begin(), starts.end(), [](const Interval& i1, const Interval& i2) {
            return i1.start < i2.start;
        });
        sort(ends.begin(), ends.end(), [](const Interval& i1, const Interval& i2) {
            return i1.end < i2.end;
        });
        int rooms = 0;

        int starti = 0;
        int endi = 0;
        int conflicts = 0;
        while (starti < intervals.size() && endi < intervals.size()) {
            if (ends[endi].end <= starts[starti].start) {
                ++endi;
                --conflicts;
                conflicts = max(0, conflicts);
            } else {
                ++conflicts;
                ++starti;
                rooms = max(rooms, conflicts);
            }
        }
        
        return rooms;
    }
};
