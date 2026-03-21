class Solution {
public:
    // int histogram(vector<int>& res, int left, int right) {

    //     if (left > right)
    //         return 0;

    //     int minindex = left;

    //     for (int i = left; i <= right; i++) {
    //         if (res[i] < res[minindex]) {
    //             minindex = i;
    //         }
    //     }

    //     int area = res[minindex] * (right - left + 1);

    //     int leftarea = histogram(res, left, minindex - 1);
    //     int rightarea = histogram(res, minindex + 1, right);

    //     return max({area, leftarea, rightarea});
    // }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        // vector<int> res(col, 0);

        // int maxarea = 0;

        // for (int i = 0; i < row; i++) {

        //     for (int j = 0; j < col; j++) {

        //         if (matrix[i][j] == '1')
        //             res[j] += 1;
        //         else
        //             res[j] = 0;
        //     }

        //     maxarea = max(maxarea, histogram(res, 0, col - 1));
        // }

        // return maxarea;

        vector<int> height(col, 0);
        vector<int> left(col, 0);
        vector<int> right(col, col);

        int maxArea = 0;

        for (int i = 0; i < row; i++) {

            int curr_left = 0, curr_right = col;

            // 1. update height
            for (int j = 0; j < col; j++) {

                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            // 2. update left
            for (int j = 0; j < col; j++) {

                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curr_left);
                }

                else {
                    left[j] = 0;
                    curr_left = j + 1;
                }
            }

            // 3. update right
            for (int j = col - 1; j >= 0; j--) {

                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curr_right);
                }

                else {
                    right[j] = col;
                    curr_right = j;
                }
            }

            for (int j = 0; j < col; j++) {
                int area = height[j] * (right[j] - left[j]);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

