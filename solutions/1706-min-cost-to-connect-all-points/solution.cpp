class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {

        int a = find(x);
        int b = find(y);

        if (a == b)
            return;

        if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else {
            parent[a] = b;  
            rank[b]++;       
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;
        int cnt = 0;

        for (auto &e : edges) {

            int w = e[0];
            int u = e[1];
            int v = e[2];

            if (find(u) != find(v)) {

                unite(u, v);

                cost += w;
                cnt++;

                if (cnt == n - 1)
                    break;
            }
        }

        return cost;
    }
};
