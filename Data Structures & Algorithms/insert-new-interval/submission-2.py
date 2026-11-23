class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        new_start = newInterval[0]
        new_end = newInterval[1]

        new_intervals = []
        inserted = None
        for i in range(len(intervals)):
            start = intervals[i][0]
            end = intervals[i][1]

            if new_start < start and inserted is None:
                new_intervals.append([-1, -1])
                inserted = len(new_intervals) - 1

            if new_start <= end and new_end >= start:
                # merge
                new_start = min(new_start, start)
                new_end = max(new_end, end)
            else:
                new_intervals.append(intervals[i])
                
        if inserted is None:
            new_intervals.append([new_start, new_end])
        else:
            new_intervals[inserted] = [new_start, new_end]
        return new_intervals
