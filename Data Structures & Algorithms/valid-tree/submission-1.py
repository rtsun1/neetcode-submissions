class DSU:
    def __init__(self):
        self.parents = {}
    
    def make_set(self, i):
        self.parents[i] = i

    def find(self, v):
        while self.parents[v] != v:
            v = self.parents[v]
        return v
    
    def union(self, v1, v2):
        v1 = self.find(v1)
        self.parents[v1] = v2
    
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        components = DSU()
        for i in range(n):
            components.make_set(i)
        n_components = n
        for edge in edges:
            v1 = edge[0]
            v2 = edge[1]
            if components.find(v1) == components.find(v2):
                return False
            components.union(v1, v2)
            n_components -= 1
        return n_components == 1