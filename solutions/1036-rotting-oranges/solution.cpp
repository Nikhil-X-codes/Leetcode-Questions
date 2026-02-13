class Solution {
public:

    bool issafe(int x,int y,int m,int n){
       return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
         
         int m=grid.size();
         int n=grid[0].size();

         queue<pair<int,int>>q;
         int fresh=0;

         for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j] == 2){
                    q.push({i,j});
                }

                else if(grid[i][j] == 1) fresh++;
            }
         }

         if(fresh == 0) return 0;
         
         int count = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()){

        int size = q.size();
        bool flag = false; 

        for(int i=0;i<size;i++){
           
           auto [x,y] = q.front();
           q.pop();

           for(int d=0;d<4;d++){
             
             int nx=x+dx[d];
             int ny=y+dy[d];

             if(issafe(nx,ny,m,n) && grid[nx][ny] == 1){
                grid[nx][ny] = 2;
                q.push({nx, ny});
                fresh--;
                flag = true;
             }

           }

        }

        if(flag){
            count++;
        }

        }

        if(fresh > 0) return -1;
        
        return count;
    }
};
