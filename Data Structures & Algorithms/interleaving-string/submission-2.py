class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        memo = {}
        def recurse(i1, i2):
            if i2 == len(s2) and i1 == len(s1):
                return True

            if (i1, i2) in memo:
                return memo[(i1, i2)]
            
            i3 = i1 + i2
            result1 = False
            result2 = False
            # add string1 "a"
            if i1 < len(s1):
                if s3[i3] == s1[i1]:
                    result1 = recurse(i1 + 1, i2)
            # add string2 "b"
            if i2 < len(s2):
                if s3[i3] == s2[i2]:
                    result2 = recurse(i1, i2 + 1)

            memo[(i1, i2)] = result1 or result2
            return result1 or result2

        if len(s1) + len(s2) != len(s3): return False
        return recurse(0, 0)