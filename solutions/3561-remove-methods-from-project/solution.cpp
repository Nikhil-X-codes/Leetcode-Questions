class Solution {
public:
    void solve(vector<vector<int>>& adj, int k, vector<bool>& sus) {

        sus[k] = true;

        for (int neigh : adj[k]) {

            if (!sus[neigh]) {
                solve(adj, neigh, sus);
            }
        }

    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto& in : invocations) {
            int u = in[0];
            int v = in[1];

            adj[u].push_back(v);
        }

        vector<int> res;
        vector<bool> sus(n, false);

        solve(adj, k, sus);

        // it checks any non sus -> sus

        for (auto& in : invocations) {
            int u = in[0];
            int v = in[1];

            if (!sus[u] && sus[v]) {

                vector<int> res;

                for (int i = 0; i < n; i++) {
                    res.push_back(i);
                }

                return res;
            }
        }

        for (int i = 0; i < n; i++) {

            if (!sus[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
