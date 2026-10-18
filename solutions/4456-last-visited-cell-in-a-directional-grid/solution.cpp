class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    void solve(vector<vector<char>>& grid, int i, int j,
               int& lastr, int& lastc) {

        visited[i][j] = true;
        lastr = i;
        lastc = j;

        int newr = i;
        int newc = j;

        if (grid[i][j] == 'L') newc--;
        else if (grid[i][j] == 'R') newc++;
        else if (grid[i][j] == 'U') newr--;
        else newr++;

        if (newr < 0 || newr >= m ||
            newc < 0 || newc >= n)
            return;

        if (visited[newr][newc])
            return;

        solve(grid, newr, newc, lastr, lastc);
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int lastr = 0;
        int lastc = 0;

        solve(grid, 0, 0, lastr, lastc);

        return {lastr, lastc};
    }
};
