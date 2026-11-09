class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        memo = {}
        def recurse(pos1: int, pos2: int) -> int:
            # assuming we already looked up to pos1 and pos2, what
            # is the longest remaining subsequence?
            if pos1 == len(text1) or pos2 == len(text2):
                return 0

            if (pos1, pos2) in memo:
                return memo[(pos1, pos2)]

            if text1[pos1] == text2[pos2]:
                result = 1 + recurse(pos1 + 1, pos2 + 1)
            else:
                result = max(
                    recurse(pos1, pos2 + 1), 
                    recurse(pos1 + 1, pos2)
                )
            memo[(pos1, pos2)] = result
            return result

        return recurse(0, 0)