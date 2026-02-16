class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        
        vector<vector<int>>adj(n);
        vector<int>res;
        vector<int>indegree(n,0);
        queue<int>q;

        for(auto &e:edges){
           int u=e[0];
           int v=e[1];
            
           adj[u].push_back(v);
           adj[v].push_back(u);

           indegree[u]++;
           indegree[v]++;
        }

        for(int i=0;i<n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        
       while(n > 2){
          int size = q.size();
          n -= size;

          for(int i=0;i<size;i++){
             int node = q.front();
             q.pop();

             for(int neigh : adj[node]){
                indegree[neigh] -- ;

                if(indegree[neigh] == 1){
                    q.push(neigh);
                }
             }
          }
       }

        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
