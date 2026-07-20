class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> dist(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    dist[nx][ny] == -1) {

                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }

        return dist;
    }
};
