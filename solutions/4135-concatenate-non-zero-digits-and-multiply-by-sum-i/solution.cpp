class Solution {
public:
    long long sumAndMultiply(int n) {

        vector<long long> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        long long sum = accumulate(digits.begin(), digits.end(), 0LL);
        reverse(digits.begin(), digits.end());

        long long x = 0;

        for (long long d : digits) {
            if (d != 0)
                x = x * 10 + d;
        }

        return x * sum;
    }
};
