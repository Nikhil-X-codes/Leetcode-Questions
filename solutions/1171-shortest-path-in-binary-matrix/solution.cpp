class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<tuple<int,int,int>> q;

        q.push({0, 0, 1});

        grid[0][0] = 1;

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {

            auto [x, y, dist] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return dist;

            for(int i = 0; i < 8; i++) {

                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < n &&
                   grid[nx][ny] == 0) {

                    q.push({nx, ny, dist + 1});

                    grid[nx][ny] = 1;
                }
            }
        }

        return -1;
    }
};
