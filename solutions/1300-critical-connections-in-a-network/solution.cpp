class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& tin,
             vector<int>& low, vector<bool>& visited, int& timer,
             vector<vector<int>>& output) {

        visited[node] = true;
        tin[node] = low[node] = timer++;

        for (auto neighbor : adj[node]) {

            if (neighbor == parent)
                continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, adj, tin, low, visited, timer, output);

                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > tin[node]) {
                    output.push_back({node, neighbor});
                }
            }

            else {
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        vector<vector<int>> output;

        for (auto& i : connections) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, tin, low, visited, timer, output);
            }
        }

        return output;
    }
};
