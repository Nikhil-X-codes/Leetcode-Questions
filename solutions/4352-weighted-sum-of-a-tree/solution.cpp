class Solution {
public:
    void dfs(int st, vector<vector<int>>& adj, int &height, int depth,vector<int>& d) {

        d[st] = depth;
        height = max(height, depth);

        for (int neigh : adj[st]) {
            dfs(neigh, adj, height, depth + 1,d);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> d(n);
        long long sum = 0;
        int height = 0;

        dfs(0, adj, height, 1, d);

        for (int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (height - d[i] + 1);
        }

        return sum;
    }
};
