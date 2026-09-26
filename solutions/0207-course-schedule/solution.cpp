class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        queue<int> q;

        for (auto &p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            // prerequisite → course
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return count == n;
    }
};
