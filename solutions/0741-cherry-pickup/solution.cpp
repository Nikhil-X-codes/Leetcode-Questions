class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    // int solve(int r1, int c1, int r2,
    //           vector<vector<int>>& grid) {

    //     int c2 = r1 + c1 - r2;

    //     if(r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
    //        grid[r1][c1] == -1 || grid[r2][c2] == -1)
    //         return -1e9;

    //     if(r1 == n-1 && c1 == n-1)
    //         return grid[r1][c1];

    //     if(dp[r1][c1][r2] != -1)
    //         return dp[r1][c1][r2];

    //     int cherries = 0;

    //     if(r1 == r2 && c1 == c2)
    //         cherries = grid[r1][c1];
    //     else
    //         cherries = grid[r1][c1] + grid[r2][c2];

    //     int a = solve(r1+1, c1, r2+1, grid); // D D
    //     int b = solve(r1+1, c1, r2, grid);   // D R
    //     int c = solve(r1, c1+1, r2+1, grid); // R D
    //     int d = solve(r1, c1+1, r2, grid);   // R R

    //     cherries += max({a,b,c,d});

    //     return dp[r1][c1][r2] = cherries;
    // }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();

        dp.resize(n,
                  vector<vector<int>>(n,
                  vector<int>(n, -1e9)));

        dp[0][0][0] = grid[0][0];

        for (int r1 = 0; r1 < n; r1++) {

            for (int c1 = 0; c1 < n; c1++) {

                for (int r2 = 0; r2 < n; r2++) {

                    int c2 = r1 + c1 - r2;
                    
                    if (c2 < 0 || c2 >= n) {
                        continue;
                    }

                    if (grid[r1][c1] == -1 ||
                        grid[r2][c2] == -1)
                        continue;

                    if (r1 == 0 && c1 == 0 && r2 == 0)
                        continue;

                    int best = -1e9;

                    if (r1 > 0 && r2 > 0)
                        best = max(best,
                                   dp[r1 - 1][c1][r2 - 1]);

                    if (r1 > 0 && c2 > 0)
                        best = max(best,
                                   dp[r1 - 1][c1][r2]);

                    if (c1 > 0 && r2 > 0)
                        best = max(best,
                                   dp[r1][c1 - 1][r2 - 1]);

                    // left left
                    if (c1 > 0 && c2 > 0)
                        best = max(best,
                                   dp[r1][c1 - 1][r2]);

                    if (best < 0)
                        continue;

                    int cherries = 0;

                    if (r1 == r2 && c1 == c2)
                        cherries = grid[r1][c1];
                    else
                        cherries =
                            grid[r1][c1] +
                            grid[r2][c2];

                    // best represnts max of previous and cheeries represnts
                    // current
                    dp[r1][c1][r2] = best + cherries;
                }
            }
        }

        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};
