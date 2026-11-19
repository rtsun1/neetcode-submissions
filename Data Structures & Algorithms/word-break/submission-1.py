class TrieNode:
    def __init__(self, val, is_word=False):
        self.val = val
        self.kids = {}
        self.is_word = is_word

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie_head = TrieNode("")
        for word in wordDict:
            sub = trie_head
            for i, c in enumerate(word):
                sub.kids[c] = sub.kids.get(c, TrieNode(c))
                is_word = i == len(word) - 1
                sub.kids[c].is_word = sub.kids[c].is_word or is_word
                sub = sub.kids[c]

        memo = set()
        def recurse(idx, sub, sub_start):
            if idx == len(s) and sub.val == "":
                return True
            elif idx == len(s):
                return False

            if (idx, sub_start) in memo:
                return False

            if s[idx] not in sub.kids:
                memo.add((idx, sub_start))
                return False
            sub = sub.kids[s[idx]]
            
            if (sub.is_word
                and recurse(idx + 1, trie_head, idx + 1)):
                return True

            if recurse(idx + 1, sub, sub_start):
                return True
            
            memo.add((idx, sub_start))
            return False # don't think this should ever happen
        
        return recurse(0, trie_head, 0)