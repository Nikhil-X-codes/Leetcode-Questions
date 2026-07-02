class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        health -= grid[0][0];

        if (health <= 0)
            return false;

        vector<vector<int>> best(m, vector<int>(n, INT_MIN));

        queue<pair<int, pair<int, int>>> q;

        q.push({health, {0, 0}});

        best[0][0] = health;

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {

            int h = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (auto& d : dir) {

                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int newh = h - grid[nx][ny];

                if (newh <= 0)
                    continue;

                if (newh <= best[nx][ny])
                    continue;

                best[nx][ny] = newh;

                q.push({newh, {nx, ny}});
            }
        }

        return false;
    }
};
