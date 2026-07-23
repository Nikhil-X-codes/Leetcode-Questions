class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {

        if (parent[i] == i)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {

        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {

            if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }

            else if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }

            else {
                parent[s1] = s2;
                rank[s1]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

int V =edges.size();

        parent.resize(V+1);
        rank.resize(V+1);

        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)) {
                return edge;
            }

            unite(u, v);
        }

        return {};
    }
};
