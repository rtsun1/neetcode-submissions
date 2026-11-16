from collections import deque
import string

# def can_visit(w1, w2):
#     if len(w1) != len(w2):
#         return False

#     mismatches = 0
#     for i in range(len(w1)):
#         if w1[i] != w2[i]:
#             mismatches += 1
#             if mismatches > 1:
#                 return False

#     return True

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        queue = deque()

        self.word_list = set(wordList)

        queue.append(beginWord)
        layers = 1
        visited = set()
        while queue: # O(n)
            layer_size = len(queue)
            # print(queue, layer_size)
            for i in range(layer_size):
                word = queue.popleft()
                if word == endWord:
                    return layers
                visited.add(word)
                queue.extend([w for w in self.kids(word) if w not in visited])
                # print(word, queue)
            layers += 1
            # print()

        return 0
        
    def kids(self, word):
        neis = []
        for i in range(len(word)): # O(n) to go through all word -> O(m) to go through each index and mutate
            # print(word, candidate, can_visit(word, candidate))
            for c in string.ascii_lowercase: # O(23) = O(1)
                candidate = word[:i] + c # O(m) to make a new string
                if i != len(word) - 1:
                    candidate += word[i + 1:]
                if candidate in self.word_list: # O(m) -> O(1) to check in set
                    neis.append(candidate)
        return neis
