class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int sign = 1;
        long ans = 0;
        int i = 0;

        while (i < n and s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }

        else if (s[i] == '+') {
            i++;
        }

        while (i < n) {

            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');

                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;

            } else {
                return sign * ans;
            }
        }

        return sign * ans;
    }
};
