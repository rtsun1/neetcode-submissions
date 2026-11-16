from collections import deque

def can_visit(w1, w2):
    if len(w1) != len(w2):
        return False

    mismatches = 0
    for i in range(len(w1)):
        if w1[i] != w2[i]:
            mismatches += 1
            if mismatches > 1:
                return False

    return True

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        queue = deque()

        self.word_list = wordList

        queue.append(beginWord)
        layers = 1
        visited = set()
        visited.add(beginWord)
        while queue: # O(n)
            layer_size = len(queue)
            # print(queue, layer_size)
            for i in range(layer_size):
                word = queue.popleft()
                if word == endWord:
                    return layers
                for w in self.kids(word):
                    if w not in visited:
                        queue.append(w)
                        visited.add(w)
                queue.extend([w for w in self.kids(word) if w not in visited])
                # print(word, queue)
            layers += 1
            # print()

        return 0
        
    def kids(self, word):
        neis = []
        for candidate in self.word_list: # O(n)
            # print(word, candidate, can_visit(word, candidate))
            if can_visit(word, candidate): # O(m)
                neis.append(candidate)
        return neis