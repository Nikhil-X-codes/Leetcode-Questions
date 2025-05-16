class Solution {
public:
   
   void solve(int node,vector<vector<int>>& graph,vector<vector<int>>&output,vector<int>&res){

    res.push_back(node);

    if(node == graph.size()-1){
       output.push_back(res);
    }
    
    else{

      for(int next:graph[node]){
       solve(next,graph,output,res);
      }

    }

    res.pop_back();

   }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>output;
        vector<int>res;
        solve(0,graph,output,res);

        return output;
    }
};
