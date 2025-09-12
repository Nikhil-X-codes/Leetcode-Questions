class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = (m * n) - 1;

        while (i <= j) {

            int mid = (j - i) / 2 + i;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }

            else if (matrix[row][col] > target) {
                j = mid - 1;
            }

            else {
                i = mid + 1;
            }
        }

        return false;
    }
};
