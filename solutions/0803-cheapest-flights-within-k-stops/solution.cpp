class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];

        for (auto& f : flights) {

            int u = f[0];
            int v = f[1];
            int cost = f[2];

            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        dist[src] = 0;

        while (!q.empty()) {

            auto [stop, temp] = q.front();
            q.pop();

            auto [node, cost] = temp;

            if (stop > k)
                continue;

            for (auto& neigh : adj[node]) {

                int neighnode = neigh.first;
                int neighwt = neigh.second;

                if (cost + neighwt < dist[neighnode]) {

                    dist[neighnode] = cost + neighwt;

                    q.push({stop + 1, {neighnode, dist[neighnode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
