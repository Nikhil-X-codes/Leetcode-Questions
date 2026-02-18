class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for(auto &t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, INT_MAX);
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            
            if(time > dist[node]) continue;
            
            for(auto &nbr : adj[node]){
                int v = nbr.first;
                int w = nbr.second;
                
                if(dist[node] + w < dist[v]){
                    dist[v] = dist[node] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};

