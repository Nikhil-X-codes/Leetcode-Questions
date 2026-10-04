class Solution {
public:

    int getCost(int a, int b) {
        int diff = abs(a - b);
        return min(diff, 10 - diff);
    }

    int minRotations(int n, string s) {

        int sum = 0;
        int curr = 0;

        for (int i = 0; i < n; i++) {

            int next = s[i] - '0';

            int diff = min(abs(curr - next), 10 - abs(curr - next));

            sum += diff;
            curr = next;
        }

        int ans = sum;

        for (int k = 0; k < n; k++) {

            int newcost = 0;

            if (k == 0) {

                int oldcost = getCost(0, s[0] - '0');

                int updatedcost = getCost(0, s[n - 1] - '0');

                newcost = sum - oldcost + updatedcost;
            }

            else {

                int oldcost = getCost(s[k - 1] - '0', s[k] - '0');

                int updatedcost = getCost(s[k - 1] - '0', s[n - 1] - '0');

                newcost = sum - oldcost + updatedcost;
            }

            ans = min(ans, newcost);
        }

        return ans;
    }
};
