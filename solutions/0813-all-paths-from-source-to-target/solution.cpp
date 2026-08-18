class Solution {
public:

    void solve(vector<vector<int>>& graph,int start,vector<vector<int>>&output,vector<int>&res){
        int n = graph.size();

         res.push_back(start);

         for(int neigh:graph[start]){
             
             if(neigh == n-1){
                res.push_back(neigh);
                output.push_back(res);
                res.pop_back();
             }

             else {
                solve(graph,neigh,output,res);
             }
         }

         res.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> output;
        vector<int>res;
        
        solve(graph,0,output,res);

        return output;
    }
};
