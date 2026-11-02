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
        // simulate going through the day and opening more rooms if needed
        vector<Interval> incoming(intervals);
        sort(incoming.begin(), incoming.end(), [](const Interval& i1, const Interval& i2) {
            return i1.start < i2.start;
        });
        priority_queue<int, vector<int>, greater<int>>meeting_end_times;
        size_t rooms = 0;
        for (auto& meeting : incoming) {
            // check what meetings have finished
            while (!meeting_end_times.empty() && meeting_end_times.top() <= meeting.start) {
                meeting_end_times.pop();
            }
            // add this meeting
            meeting_end_times.push(meeting.end);

            rooms = max(rooms, meeting_end_times.size());
        }

        return rooms;
    }
};
