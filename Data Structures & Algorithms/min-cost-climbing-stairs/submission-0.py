class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        total_costs = cost.copy()

        for i in range(len(cost) - 3, -1, -1):
            best_next = min(total_costs[i + 1], total_costs[i + 2])
            total_costs[i] = cost[i] + best_next
        
        return min(total_costs[0], total_costs[1])