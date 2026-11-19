class TrieNode:
    def __init__(self, is_word=False):
        self.kids = {}
        self.is_word = is_word

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie_head = TrieNode()
        for word in wordDict:
            sub = trie_head
            for i, c in enumerate(word):
                if c not in sub.kids:
                    sub.kids[c] = TrieNode()
                sub = sub.kids[c]
            sub.is_word = True

        memo = set()
        def recurse(idx, sub, sub_start):
            if idx == len(s) and sub is trie_head:
                return True
            elif idx == len(s):
                return False

            if sub_start in memo:
                return False

            if s[idx] not in sub.kids:
                memo.add(sub_start)
                return False
            sub = sub.kids[s[idx]]
            
            if (sub.is_word
                and recurse(idx + 1, trie_head, idx + 1)):
                return True

            if recurse(idx + 1, sub, sub_start):
                return True
            
            memo.add(sub_start)
            return False # will happen if cant complete s with suffix starting at sub_start
        
        return recurse(0, trie_head, 0)