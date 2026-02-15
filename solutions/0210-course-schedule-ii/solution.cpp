class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         
        vector<vector<int>> adj(numCourses);
        vector<int>indeg(numCourses,0);
        
        for(auto &e:prerequisites){
            
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            
            indeg[v]++;
        }
        
        queue<int>q;
        vector<int>res;
        
        for(int i=0;i<numCourses;i++){
            
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(int i:adj[node]){
                indeg[i] -- ;
                
                if(indeg[i] == 0){
                    q.push(i);
                }
            }
            
        }
          
        reverse(res.begin(),res.end());

        if(res.size() != numCourses) return {};

        return res;
    }
};
