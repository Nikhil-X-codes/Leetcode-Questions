class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {

            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int i) {

            if (parent[i] == i) {
                return i;
            }

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
                    parent[s2] = s1;
                    rank[s1]++;
                }
            }
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        for (auto& e : edges) {
            dsu.unite(e[0], e[1]);
        }

        unordered_map<int, int> nodes;
        unordered_map<int, int> edgeCount;

        for (int i = 0; i < n; i++) {
            int p = dsu.find(i);
            nodes[p]++;
        }

        for (auto& e : edges) {
            int u = dsu.find(e[0]);
            edgeCount[u]++;
        }

        int count = 0;

        for (auto& it : nodes) {

            int component = it.first;
            int nodecnt = it.second;

            int required = ((nodecnt) * (nodecnt - 1)) / 2;

            if (edgeCount[component] == required) {
                count++;
            }
        }

        return count;
    }
};
