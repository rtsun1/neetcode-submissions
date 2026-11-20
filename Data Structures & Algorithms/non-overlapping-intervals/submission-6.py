import math
import sys
from bisect import bisect_left

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        sys.setrecursionlimit(1000000)
        intervals.sort()
        memo = [-1] * len(intervals)
        def recurse(idx):
            # last interval base
            if idx >= len(intervals):
                return 0

            if memo[idx] != -1:
                return memo[idx]

            # remove
            case1 = recurse(idx + 1) + 1
            # keep
            end = intervals[idx][1]
            i = bisect_left(intervals, end, lo=idx, key=lambda x: x[0])
            removals = i - idx - 1
            case2 = removals + recurse(i)

            result = min(case1, case2)
            memo[idx] = result
            return result
        return recurse(0)
        