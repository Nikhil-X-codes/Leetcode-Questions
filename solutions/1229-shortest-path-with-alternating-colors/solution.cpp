class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,vector<vector<int>>& blueEdges) {

        if (n == 1)
            return {0};

        vector<int> res(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<vector<vector<int>>> adj(n, vector<vector<int>>(2));

        for (auto& e : redEdges) {
            int u = e[0];
            int v = e[1];

            adj[u][0].push_back(v);
        }

        for (auto& e : blueEdges) {
            int u = e[0];
            int v = e[1];

            adj[u][1].push_back(v);
        }

        queue<pair<int,int>> q;

        q.push({0, 0});
        q.push({0, 1});

        visited[0][0] = true;
        visited[0][1] = true;

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0;i<size;i++) {

                auto element = q.front();
                q.pop();

                int curr_node = element.first;
                int curr_color = element.second;

                if (res[curr_node] == -1) {
                    res[curr_node] = distance;
                }

                int next_color = 1 - curr_color;

                for (auto& nextnode : adj[curr_node][curr_color]) {

                    if (!visited[nextnode][next_color]) {
                        visited[nextnode][next_color] = true;
                        q.push({nextnode, next_color});
                    }
                }
            }

            distance++;
        }

        return res;
    }
};
