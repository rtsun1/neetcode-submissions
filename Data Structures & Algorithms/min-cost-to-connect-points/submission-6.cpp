struct Edge {
    int node1, node2;
    int cost;
    friend bool operator>(const Edge& e1, const Edge& e2) {
        return e1.cost > e2.cost;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> collected;
        vector<int> distances(points.size(), std::numeric_limits<int>::max());
        int cost = 0;
        int closest = 0;
        distances[0] = 0;
        while (collected.size() != points.size()) {
            // add to MST
            collected.insert(closest);
            cost += distances[closest];

            // update distance and remember closest
            int closest_distance = std::numeric_limits<int>::max();
            int next_closest = std::numeric_limits<int>::max();
            for (int i = 0; i < points.size(); ++i) {
                if (collected.contains(i)) {
                    continue;
                }
                distances[i] = std::min(
                    distances[i], 
                    manhattan(i, closest, points)
                );
                if (closest_distance > distances[i]) {
                    closest_distance = distances[i];
                    next_closest = i;
                }
            }
            closest = next_closest;
        }
        return cost;
    }

private:
    int manhattan(int node1, int node2, vector<vector<int>>& points) {
        return std::abs(points[node1][0] - points[node2][0]) + 
            std::abs(points[node1][1] - points[node2][1]);
    }
};
