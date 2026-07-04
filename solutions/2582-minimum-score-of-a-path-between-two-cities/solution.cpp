class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto& r : roads) {

            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        q.push(1);
        vector<bool> vis(n + 1, false);

        int ans = INT_MAX;

        vis[1] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto& neigh : adj[node]) {

                int neighnode = neigh.first;
                int neighwt = neigh.second;

                ans = min(ans, neighwt);

                if (!vis[neighnode]) {
                    vis[neighnode] = true;
                    q.push(neighnode);
                }

            }
        }

        return ans;
    }
};
