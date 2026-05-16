class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int clr,
             vector<int>& color) {

        color[node] = clr;

        for (auto& neigh : graph[node]) {

            if (color[neigh] == -1) {

                if (!dfs(graph, neigh, 1 - clr, color)) {
                    return false;
                }
            }

            else if (color[neigh] == clr) {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {

            if (color[i] == -1) {

                if (!dfs(graph,i,0,color)) {
                    return false;
                }
            }
        }

        return true;
    }
};
