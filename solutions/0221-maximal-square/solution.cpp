class Solution {
public:

    // int histogram(vector<int>& res, int left, int right) {

    //     if (left > right)
    //         return 0;

    //     int minindex = left;

    //     for (int i = left; i <= right; i++) {
    //         if (res[i] < res[minindex])
    //             minindex = i;
    //     }

    //     int width = right - left + 1;
    //     int side = min(res[minindex], width);

    //     int area = side * side;

    //     int leftarea = histogram(res, left, minindex - 1);
    //     int rightarea = histogram(res, minindex + 1, right);

    //     return max({area, leftarea, rightarea});
    // }


    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // vector<int> res(n, 0);
        // int maxarea = 0;

        // for (int i = 0; i < m; i++) {

        //     for (int j = 0; j < n; j++) {

        //         if (matrix[i][j] == '1') {
        //             res[j]++;
        //         }

        //         else {
        //             res[j] = 0;
        //         }
        //     }

        //     maxarea = max(maxarea, histogram(res, 0, m - 1));
        // }

        // return maxarea;

 vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxi = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                maxi = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (matrix[i][j] == '1') {   
                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i-1][j-1],
                        dp[i][j-1]
                    });

                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        return maxi * maxi;

    }
};
