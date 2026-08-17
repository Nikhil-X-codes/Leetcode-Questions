class Solution {
public:
    bool solve(vector<vector<int>>& graph, int start, int clr,
               vector<int> &color) {

        color[start] = clr;

        for (int neigh : graph[start]) {

            if (color[neigh] == -1) {

                if (!solve(graph, neigh, 1 - clr, color))
                    return false;
            }

            else if (color[neigh] == color[start]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                if (!solve(graph, i, 0, color))
                    return false;
            }
        }

        return true;
    }
};
