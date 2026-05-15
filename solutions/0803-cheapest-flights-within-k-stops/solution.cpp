class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         
        vector<pair<int,int>> adj[n];

        for(auto &f : flights) {

            int u = f[0];
            int v = f[1];
            int cost = f[2];

            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int,int>>> q;

        q.push({0, {src, 0}});

        dist[src] = 0;

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto &nbr : adj[node]) {

                int adjNode = nbr.first;
                int edgeCost = nbr.second;

                if(cost + edgeCost < dist[adjNode] && stops <= k) {

                    dist[adjNode] = cost + edgeCost;

                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
       
        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};
