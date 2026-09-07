class Solution {
public:

       int solve(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size())
            return 0;

        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        int area = 1;

        area += solve(grid, i + 1, j);
        area += solve(grid, i - 1, j);
        area += solve(grid, i, j + 1);
        area += solve(grid, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         
        int maxarea = 0;

        int m = grid.size();
        int n = grid[0].size();


        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                  int area = solve(grid,i,j);
                  maxarea = max(maxarea,area);
                }
            }
        }

        return maxarea;
    }
};
