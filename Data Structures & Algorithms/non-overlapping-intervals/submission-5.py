class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        removals = 0
        farthest_end = -math.inf
        for i in range(len(intervals)):
            if intervals[i][0] < farthest_end:
                # conflict
                removals += 1
                farthest_end = min(farthest_end, intervals[i][1])
            else:
                # no conflict
                farthest_end = intervals[i][1]

        return removals