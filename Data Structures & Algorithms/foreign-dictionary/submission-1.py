from collections import defaultdict, deque

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        '''
        cycle detection on a directed graph:
        topological sort with indegrees

        n is num of all chars
        make the graph: O(n)
        sort the graph: O(E)
        E can be up to n ** 2?
        '''
        adj = defaultdict(set)
        indegrees = defaultdict(int)
        constrained_chars = set()
        remaining_chars = set()
        if len(words) < 2:
            return words[0]

        last_word = words[0]
        # print(set(last_word))
        remaining_chars = remaining_chars.union(set(last_word))
        # print(remaining_chars)
        for i in range(1, len(words)):
            curr_word = words[i]
            remaining_chars = remaining_chars.union(set(curr_word))
            for j in range(len(last_word)):
                if j >= len(curr_word):
                    return ""
                
                if curr_word[j] != last_word[j]:
                    # first discrepancy: curr char is > last char
                    if curr_word[j] not in adj[last_word[j]]:
                        adj[last_word[j]].add(curr_word[j])
                        indegrees[curr_word[j]] += 1

                        constrained_chars.add(curr_word[j])
                        constrained_chars.add(last_word[j])
                    break
            last_word = curr_word
        
        frontier = deque()
        for c in adj.keys():
            if indegrees[c] == 0:
                frontier.append(c)
        
        result = []
        while frontier:
            c = frontier.popleft()
            result.append(c)
            remaining_chars.remove(c)
            for nei in adj[c]:
                indegrees[nei] -= 1
                if indegrees[nei] == 0:
                    frontier.append(nei)
        
        # print(remaining_chars, result)
        if len(result) != len(constrained_chars):
            return ""

        # add the remaining chars
        result.extend(list(remaining_chars))

        return "".join(result)


