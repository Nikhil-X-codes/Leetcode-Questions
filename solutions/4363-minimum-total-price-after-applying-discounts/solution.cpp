class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

            sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double total = 0;

        int i = 0, j = 0;

        while (i < prices.size() && j < discounts.size()) {
            total += (double)prices[i] * (100 - discounts[j]) / 100.0;
            i++;
            j++;
        }

        while (i < prices.size()) {
            total += prices[i];
            i++;
        }

        return total;
    }
};
