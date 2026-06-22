class Solution {
public:

    void solve(vector<vector<int>>& rooms, int room, int n, vector<bool>& visited) {

        visited[room] = true;

        for (int key : rooms[room]) {
            if (!visited[key]) {
                solve(rooms, key, n, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool> visited(n, false);

        solve(rooms,0,n,visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
