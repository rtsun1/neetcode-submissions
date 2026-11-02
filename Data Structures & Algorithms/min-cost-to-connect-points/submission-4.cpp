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
        priority_queue<Edge, vector<Edge>, std::greater<Edge>> cheapest_edge;

        // merge components
        int n_components = points.size();
        unordered_set<int> collected;
        int cost = 0;
        for (int i = 0; i < points.size(); ++i) {
            cheapest_edge.push({0, i, manhattan(0, i, points)});
        }
        collected.insert(0);
        while (collected.size() != points.size()) {
            Edge edge = cheapest_edge.top();
            cheapest_edge.pop();
            if (!(collected.contains(edge.node1) ^ collected.contains(edge.node2))) {
                continue;
            }

            if (collected.contains(edge.node2)) {
                std::swap(edge.node1, edge.node2);
            }
            collected.insert(edge.node2);
            for (int i = 0; i < points.size(); ++i) {
                cheapest_edge.push({edge.node2, i, manhattan(edge.node2, i, points)});
            }
            
            cost += edge.cost;
        }
        return cost;
    }

private:
    int manhattan(int node1, int node2, vector<vector<int>>& points) {
        return std::abs(points[node1][0] - points[node2][0]) + 
            std::abs(points[node1][1] - points[node2][1]);
    }
};
