class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsatis = 0;

        // Calculate initial unsatisfied customers during the first `minutes`
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                unsatis += customers[i];
            }
        }

        int maxUnsatis = unsatis;
        int i = 0;
        int j = minutes;

        // Sliding window to find the maximum unsatisfied customers
        while (j < n) {
            if (grumpy[j] == 1) {
                unsatis += customers[j];
            }
            if (grumpy[i] == 1) {
                unsatis -= customers[i];
            }
            maxUnsatis = max(maxUnsatis, unsatis);
            i++;
            j++;
        }

        int finalResult = maxUnsatis;

        // Add all initially satisfied customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                finalResult += customers[i];
            }
        }

        return finalResult;
    }
};

