class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<vector<int>> adj(numCourses);
         vector<int> indegree(numCourses, 0);

         for(auto &pre:prerequisites){
            int u=pre[0];
            int v=pre[1];

            adj[u].push_back(v);
            indegree[v]++;
         }
        
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
       
        int count = 0;

        while(!q.empty()){
           
           int node = q.front();
           q.pop();
           count++;

           for(int i:adj[node]){
            indegree[i]--;

            if(indegree[i] == 0){
                q.push(i);
            }

           }
        }
        
        return count == numCourses;
    }
};
