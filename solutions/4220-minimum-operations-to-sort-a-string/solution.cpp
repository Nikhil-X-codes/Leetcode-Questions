#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        for (int i = 0; i < n; i++) {

            if ((i < n - 1 && s[i] == mn) || (i > 0 && s[i] == mx)) {
                return 2;
            }
        }

        return 3;
    }
};
