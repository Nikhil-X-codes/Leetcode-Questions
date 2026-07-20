class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    pq.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int timer = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty() && fresh > 0) {

            int size = pq.size();

            for (int i = 0; i < size; i++) {

                auto [x, y] = pq.front();
                pq.pop();

                for (int k = 0; k < 4; k++) {

                    int nx = x + dr[k];
                    int ny = y + dc[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        grid[nx][ny] == 1) {

                        fresh--;
                        grid[nx][ny] = 2;
                        pq.push({nx, ny});
                    }
                }
            }

            timer++;
        }

        if (fresh > 0)
            return -1;

        return timer;
    }
};
