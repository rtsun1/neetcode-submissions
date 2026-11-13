class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:

        def recurse(si, ti) -> bool: 
            if ti == len(t) and si != len(s):
                return False
            elif ti == len(t) or si == len(s):
                return True

            if s[si] == t[ti]:
                result = recurse(si + 1, ti + 1) # we found s[si] == t[ti]
            else:
                result = recurse(si, ti + 1) # s[si] != t[ti]

            return result
        
        return recurse(0, 0)