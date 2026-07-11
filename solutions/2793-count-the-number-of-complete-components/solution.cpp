class Solution {
public:
    void dfs(int start, vector<vector<int>> adj, vector<bool>& vis,
             int& nodecount, int& degreesum) {

        vis[start] = true;

        nodecount++;

        degreesum += adj[start].size();

        for (int neigh : adj[start]) {

            if (!vis[neigh]) {
                dfs(neigh, adj, vis, nodecount, degreesum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {

            int nodecount = 0;
            int degreesum = 0;

            if (!vis[i]) {

                dfs(i, adj, vis, nodecount, degreesum);

                int required = degreesum / 2;
                int actual = (nodecount * (nodecount - 1)) / 2;

                if (required == actual)
                    count++;
            }
        }

        return count;
    }
};
