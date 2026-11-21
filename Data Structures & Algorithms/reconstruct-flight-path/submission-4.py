from collections import defaultdict
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        used_edges = set()
        curr_path = []
        adj_list = defaultdict(list)
        for i in range(len(tickets)):
            start, stop = tickets[i]
            adj_list[start].append((stop, i))
        for kids in adj_list.values():
            kids.sort(reverse=True)

        def hierholzer(node):
            kids = adj_list[node[0]]
            while kids:
                kid = kids.pop()
                hierholzer(kid)
            curr_path.append(node[0])


        hierholzer(("JFK", -1))

        curr_path.reverse()
        return curr_path