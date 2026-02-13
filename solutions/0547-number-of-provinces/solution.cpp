class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        
        visited[city] = true;
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int count = 0;
        
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        
        return count;
    }
};

