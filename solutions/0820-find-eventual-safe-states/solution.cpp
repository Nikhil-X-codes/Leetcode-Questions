class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n);

            for (int i = 0; i < n; i++) {

            outdegree[i] = graph[i].size();

            for (int v : graph[i]) {
                rev[v].push_back(i);
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (int neigh : rev[node]) {
                outdegree[neigh]--;

                if (outdegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
