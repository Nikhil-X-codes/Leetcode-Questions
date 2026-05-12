class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 1});

        grid[0][0] = 1;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nc < n && nr < n &&
                    grid[nr][nc] == 0) {
                    q.push({{nr, nc}, dist + 1});

                    grid[nr][nc] = 1;
                }
            }
        }
      
      return -1;
    }
};
