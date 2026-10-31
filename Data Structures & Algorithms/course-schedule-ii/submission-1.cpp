class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // kahns topological sort
        vector<int> indegrees(numCourses, 0);
        queue<int> frontier;
        vector<int> topological_ordering;
        vector<vector<int>> children(numCourses);
        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            children[b].push_back(a);
            ++indegrees[a];
        }
        for (int node = 0; node < numCourses; ++node) {
            if (indegrees[node] == 0) {
                frontier.push(node);
            }
        }

        while (!frontier.empty()) {
            int gen_size = frontier.size();
            for (int i = 0; i < gen_size; ++i) {
                int node = frontier.front();
                frontier.pop();
                topological_ordering.push_back(node);
                for (int child : children[node]) {
                    if (--indegrees[child] == 0) {
                        frontier.push(child);
                    }
                }
            }
        }

        if (std::accumulate(indegrees.begin(), indegrees.end(), 0) > 0) {
            return {};
        } 

        return topological_ordering;
    }
};
