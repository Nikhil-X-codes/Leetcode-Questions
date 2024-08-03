#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> res;

        int st_row = 0, last_row = m - 1;
        int st_col = 0, last_col = n - 1;

        while (st_row <= last_row && st_col <= last_col) {
            for (int i = st_col; i <= last_col; i++) {
                res.push_back(matrix[st_row][i]);
            }
            st_row++;

            for (int i = st_row; i <= last_row; i++) {
                res.push_back(matrix[i][last_col]);
            }
            last_col--;

            if (st_row <= last_row) {
                for (int i = last_col; i >= st_col; i--) {
                    res.push_back(matrix[last_row][i]);
                }
                last_row--;
            }

            if (st_col <= last_col) {
                for (int i = last_row; i >= st_row; i--) {
                    res.push_back(matrix[i][st_col]);
                }
                st_col++;
            }
        }

        return res;
    }
};

