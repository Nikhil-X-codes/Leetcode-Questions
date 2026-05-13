class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;

        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();

            for (int v : graph[u]) {
                revGraph[v].push_back(u);
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            res.push_back(node);

            for (int i : revGraph[node]) {
                outdegree[i]--;

                if (outdegree[i] == 0) {
                    q.push(i);
                }
            }
        }
       
        sort(res.begin(),res.end());

        return res;
    }
};
