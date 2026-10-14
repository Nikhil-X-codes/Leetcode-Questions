class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (num == 0 || sum > 9 * num)
            return "";
        string ans = "";

        for (int i = 0; i < num; i++) {
            int d = min(9, sum);
            ans += '0' + d;
            sum -= d;
        }

        return ans;
    }
};
