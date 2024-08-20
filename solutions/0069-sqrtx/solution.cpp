class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Handle the base cases

        long long result = 1;

        // Increment result until result^2 exceeds x
        while (result * result <= x) {
            result++;
        }

        return result - 1;  // Subtract 1 because result^2 is now greater than x
    }
};

