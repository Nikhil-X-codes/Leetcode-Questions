
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int size = nums.size();

        int i = 0;
        int j = 0;
        int maxleng = 0;

        // Max heap for the maximum value in the current window
        priority_queue<pair<int, int>> maxpq; 
        // Min heap for the minimum value in the current window
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

        while (j < size) {
            maxpq.push({nums[j], j});
            minpq.push({nums[j], j});

            while (maxpq.top().first - minpq.top().first > limit) {
                i = min(maxpq.top().second, minpq.top().second) + 1;
                while (!maxpq.empty() && maxpq.top().second < i) {
                    maxpq.pop();
                }
                while (!minpq.empty() && minpq.top().second < i) {
                    minpq.pop();
                }
            }

            maxleng = max(maxleng, j - i + 1);
            j++;
        }

        return maxleng;
    }
};

