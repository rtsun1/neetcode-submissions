class DSU:
    def __init__(self):
        self.parents = {}
        self.sizes = {}
    
    def make_set(self, i):
        self.parents[i] = i
        self.sizes[i] = 1

    def find(self, v):
        while self.parents[v] != v:
            parent = self.parents[v]
            self.parents[v] = self.parents[parent]
            v = parent
        return v
    
    def union(self, v1, v2):
        v1 = self.find(v1)
        v2 = self.find(v2)
        if self.sizes[v1] > self.sizes[v2]:
            v1, v2 = v2, v1

        self.parents[v1] = v2
        self.sizes[v2] += self.sizes[v1]
    
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