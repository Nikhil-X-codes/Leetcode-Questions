class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<bool> visited(n, false);

        pq.push({0, 0});

        int cost = 0;
        int edgeused = 0;

        while (edgeused < n) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (visited[node]) {
                continue;
            }

            edgeused++;

            visited[node] = true;

            cost += wt;

            for (int i = 0; i < n; i++) {

                if (!visited[i]) {
                    int newpoint = abs(points[node][0] - points[i][0]) +
                                   abs(points[node][1] - points[i][1]);

                    pq.push({newpoint, i});
                }
            }
        }

        return cost;
    }
};
