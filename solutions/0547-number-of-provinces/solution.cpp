class Solution {
public:
    void solve(vector<vector<int>>& adj, int start, vector<bool>& vis) {

        vis[start] = true;

        for (int neigh : adj[start]) {
            if (!vis[neigh]) {
                solve(adj, neigh, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int count = 0;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                solve(adj, i, vis);
            }
        }

        return count;
    }
};
