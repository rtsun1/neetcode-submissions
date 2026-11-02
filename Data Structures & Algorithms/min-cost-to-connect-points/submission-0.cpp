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

        // build cheapest edge
        // & init components
        vector<unordered_set<int>> component_storage(points.size());

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                cheapest_edge.push(Edge{i, j, manhattan(i, j, points)});
            }
            component_storage[i].insert(i);
            components[i] = &(component_storage[i]);
        }

        // merge components
        int n_components = points.size();
        int cost = 0;
        while (n_components != 1) {
            Edge edge = cheapest_edge.top();
            cheapest_edge.pop();
            int node1 = edge.node1;
            int node2 = edge.node2;
            if (components.at(node1) == components.at(node2)) {
                continue;
            }
            
            merge_components(node1, node2);
            --n_components;
            cost += edge.cost;
        }
        return cost;
    }

private:
    unordered_map<int, unordered_set<int>*> components;
    void merge_components(int node1, int node2) {
        int smaller, larger;
        if (components.at(node1)->size() <= components.at(node2)->size()) {
            smaller = node1;
            larger = node2;
        } else {
            smaller = node2;
            larger = node1;
        }

        unordered_set<int>* larger_component = components[larger];
        for (int node : *(components[smaller])) {
            larger_component->insert(node);
            components[node] = larger_component;
        }
    }
    int manhattan(int node1, int node2, vector<vector<int>>& points) {
        return std::abs(points[node1][0] - points[node2][0]) + 
            std::abs(points[node1][1] - points[node2][1]);
    }
};
