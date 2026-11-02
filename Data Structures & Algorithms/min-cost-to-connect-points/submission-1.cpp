struct Edge {
    int v1, v2;
    int cost;
    friend bool operator<(const Edge& e1, const Edge& e2) {
        return e1.cost < e2.cost;
    }
};
class DSU {
    public:
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find_set(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return;
        }
        if (size[b] < size[a]) {
            std::swap(a, b);
        }
        parent[a] = b;
        size[b] += size[a];
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> cheapest_edge;
        // init components
        DSU dsu(points.size());
        // build cheapest edge
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                cheapest_edge.push_back(Edge{i, j, manhattan(i, j, points)});
            }
        }
        std::sort(cheapest_edge.begin(), cheapest_edge.end());

        // merge components
        int cost = 0;
        for (Edge& edge : cheapest_edge) {
            if (dsu.find_set(edge.v1) == dsu.find_set(edge.v2)) {
                continue;
            }
            dsu.union_set(edge.v1, edge.v2);
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
