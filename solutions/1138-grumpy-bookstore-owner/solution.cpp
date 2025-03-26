class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0, extra_customers = 0, current_window = 0;

        for (int k = 0; k < customers.size(); k++) {
            if (grumpy[k] == 0) {
                satisfied += customers[k];
            }
        }

        for (int k = 0; k < minutes; k++) {
            if (grumpy[k] == 1) {
                current_window += customers[k];
            }
        }

        extra_customers = current_window;

        for (int k = minutes; k < customers.size(); k++) {
            if (grumpy[k] == 1) {
                current_window += customers[k];
            }
            if (grumpy[k - minutes] == 1) {
                current_window -= customers[k - minutes];
            }
            extra_customers = max(extra_customers, current_window);
        }

        return satisfied + extra_customers;
    }
};

