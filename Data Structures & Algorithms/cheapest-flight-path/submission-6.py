import heapq
# from collections import defaultdict
from collections import deque
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        '''
        sol1: run dijkstra with layer limit 1 - k (k dijkstra's)
        sol2: run bfs until you get to layer k. greedy track the best cost to dst
        sol3: run dijkstra with node reexpansion if layer is smaller than before
        '''
        visited = {} # node : min stops to get here
        queue = []
        # print(src, dst, k)
        # adj_list = defaultdict(list)
        adj_list = {}
        for start, stop, price in flights:
            kids = adj_list.setdefault(start, [])
            kids.append((stop, price))

        if src not in adj_list:
            return -1
        for kid, price in adj_list[src]: # can do this b/c src != dst, and n >= 1
            heapq.heappush(queue, (price, kid, 0))

        while queue:
            cost_so_far, node, path_len = heapq.heappop(queue)
            if node in visited and visited[node] <= path_len:
                continue
            visited[node] = path_len
            if node == dst:
                return cost_so_far

            if node not in adj_list or path_len + 1 > k:
                continue
            for kid, price in adj_list[node]:
                heapq.heappush(queue, (cost_so_far + price, kid, path_len + 1))
                
        return -1
