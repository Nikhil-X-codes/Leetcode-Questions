class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
                          vector<double>& succProb, 
                          int start_node, int end_node) {
         
        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        priority_queue<pair<double,int>> q;
        q.push({1.0, start_node});

        while(!q.empty()){

            auto [curr_prob, curr_node] = q.top();
            q.pop();

            if(curr_node == end_node) 
                return curr_prob;

            for(auto &neigh : adj[curr_node]){
                
                int next_node = neigh.first;
                double edge_prob = neigh.second;

                double new_prob = curr_prob * edge_prob;

                if(new_prob > prob[next_node]) {
                    prob[next_node] = new_prob;
                    q.push({new_prob, next_node});
                }
            }
        }
        
        return 0.0;
    }
};

