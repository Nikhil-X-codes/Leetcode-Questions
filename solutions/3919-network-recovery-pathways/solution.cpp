class Solution {
public:
    bool check(int limit, vector<vector<pair<int, int>>> &adj,
               vector<bool> &online, long long k) {

        int n = online.size();

        vector<long long> dist(n, LLONG_MAX);

        using State = pair<long long, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u])
                continue;

            for (auto &neigh : adj[u]) {

                int neighnode = neigh.first;
                int neighwt = neigh.second;

                if (neighwt < limit)
                    continue;

                if (neighnode != n - 1 && !online[neighnode])
                    continue;

                long long newCost = cost + neighwt;

                if (newCost > k)
                    continue;

                if (newCost < dist[neighnode]) {
                    dist[neighnode] = newCost;
                    pq.push({dist[neighnode], neighnode});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);

        int mx = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        int lo = 0;
        int hi = mx;
        int ans = -1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (check(mid, adj, online, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
