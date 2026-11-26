class DSU {
public:
    DSU(int n) {
        sizes = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        n_sets = n;
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = this->find(parent[v]);
        }
        return parent[v];
    }

    void union_sets(int v, int u) {
        v = this->find(v);
        u = this->find(u);

        if (v == u) {
            return;
        }

        if (sizes[v] > sizes[u]) {
            swap(v, u);
        }
        
        parent[v] = u;
        sizes[u] += sizes[v];
        --n_sets;
    }

    int get_n_sets() {
        return n_sets;
    }

private:
    unordered_map<int, int> parent;
    vector<int> sizes;
    int n_sets;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU sets{n};

        for (vector<int> edge : edges) {
            int v = edge[0];
            int u = edge[1];
            
            sets.union_sets(v, u); 
        }

        return sets.get_n_sets();
    }
};
