class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        int time = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            bool flag = false;
            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (isvalid(grid, nx, ny) && grid[nx][ny] == 1) {

                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        flag = true;
                    }
                }
            }

            if (flag) {
                time++;
            }
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};
