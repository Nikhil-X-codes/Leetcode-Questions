class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        int allVisited = (1 << n) - 1;

        queue<pair<int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // multi sorce BFS
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [p, r] = q.front();
                q.pop();

                if (r == allVisited) {
                    return steps;
                }

                for (int neigh : graph[p]) {
                    // means newMask = old visited nodes + current neighbor
                    int newmask = r | (1 << neigh);

                    if (!visited[neigh][newmask]) {
                        visited[neigh][newmask] = true;
                        q.push({neigh, newmask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
