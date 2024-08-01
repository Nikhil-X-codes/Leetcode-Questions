class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int maxsum = 0;

        // Calculate the initial sum of the first k elements
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        // Initialize maxsum with the initial lsum
        maxsum = lsum;

        // Use a sliding window approach to calculate the maximum score
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];  // Remove the element from the left end
            rsum += cardPoints[cardPoints.size() - 1 - i];  // Add the element from the right end
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};

