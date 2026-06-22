class Solution {
public:
    void solve(vector<vector<int>>& adj, int n, int node, vector<bool>& visited,
               int& nodecount, int& degreesum) {

        visited[node] = true;

        nodecount++;
        degreesum += adj[node].size();

        for (int neigh : adj[node]) {

            if (!visited[neigh]) {
                solve(adj, n, neigh, visited, nodecount, degreesum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        vector<bool> visited(n, false);
        int ccount = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                int nodecount = 0;
                int degreesum = 0;

                solve(adj, n, i, visited, nodecount, degreesum);

                int actualedges = degreesum / 2;
                int requiredges = (nodecount * (nodecount - 1)) / 2;

                if (actualedges == requiredges)
                    ccount++;
            }
        }

        return ccount;
    }
};
