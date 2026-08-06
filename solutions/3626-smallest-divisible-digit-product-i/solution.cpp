class Solution {
public:
    int smallestNumber(int n, int t) {

        int num = n;

        while (num) {

            int temp = num;
            int prod = 1;

            while (temp > 0) {
                int digit = temp % 10;
                prod *= digit;
                temp /= 10;
            }

            if (prod % t == 0) {
                return num;
            }

            num++;
        }

        return -1;
    }
};
