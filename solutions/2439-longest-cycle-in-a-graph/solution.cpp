class Solution {
public:
    int ans = -1;

    void solve(vector<int>& edges, int start, vector<int>& res,
               vector<bool>& visited, int count) {

        res[start] = count;
        visited[start] = true;

        int next = edges[start];

        if (next != -1) {

            if (!visited[next]) {
                solve(edges, next, res, visited, count + 1);
            }

            else {
                if (res[next] != 0) {
                    ans = max(ans, count - res[next] + 1);
                }
            }
        }

        res[start] = 0;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        vector<int> res(n, 0);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                solve(edges, i, res, visited, 1);
            }
        }

        return ans;
    }
};
