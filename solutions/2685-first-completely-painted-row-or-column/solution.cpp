class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int,pair<int, int>>mp;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                int value=mat[i][j];
                mp[value]={i,j};
            }
        }

        vector<int>row(m,0);
        vector<int>col(n,0);

        for(int j=0;j<arr.size();j++){
          
          int val=arr[j];
          auto [rows,cols]=mp[val];

          row[rows]++;
          col[cols]++;

          if( row[rows] == n or  col[cols]== m){
            return j;
          }
        }

return -1;
    }
};
