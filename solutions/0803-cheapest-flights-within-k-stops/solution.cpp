class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        vector<int>distance(n,INT_MAX);

        for(auto &f:flights){
           int u=f[0];
           int v=f[1];
           int w=f[2];

           adj[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        distance[src] = 0;

        while(!q.empty()){
          auto element = q.front();
          q.pop();

          int stop = element.first;
          int node = element.second.first;
          int cost = element.second.second;

          if(stop > k) continue;

          for(auto neigh:adj[node]){
            
            int next_node=neigh.first;
            int edge_weight=neigh.second;

            if(cost + edge_weight < distance[next_node] && stop <= k){
               distance[next_node] = cost + edge_weight;
               q.push({stop+1,{next_node, cost + edge_weight}});
            }

          }
          
        }

        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};
