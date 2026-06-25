class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {

        if (x < 0 || x >= m || y < 0 || y >= n)
            return;

        if (board[x][y] != 'O')
            return;

        board[x][y] = '#';

        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();

        if (m == 0)
            return;

        n = board[0].size();

        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {

            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
