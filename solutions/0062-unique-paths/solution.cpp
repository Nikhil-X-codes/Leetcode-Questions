class Solution {
public:
  
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(0, 0, m, n, memo);
    }

    int solve(int i, int j, int m, int n, vector<vector<int>>& memo) {

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (i >= m || j >= n) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int right = solve(i, j + 1, m, n, memo);
        int down = solve(i + 1, j, m, n, memo);

        memo[i][j] = right + down;
        return memo[i][j];
    }
};

