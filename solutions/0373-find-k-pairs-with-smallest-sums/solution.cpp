class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                      vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m = nums1.size();
        int n = nums2.size();

        if (m == 0 || n == 0 || k <= 0)
            return ans;

        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>> pq;

        // Insert the first pair of each row
        for (int i = 0; i < min(k, m); i++) {
            pq.push({0LL + nums1[i] + nums2[0], i, 0});
        }

        while (!pq.empty() && k > 0) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});
            k--;

            // Push the next pair from the same row
            if (j + 1 < n) {
                pq.push({0LL + nums1[i] + nums2[j + 1],
                         i, j + 1});
            }
        }

        return ans;
    }
};
