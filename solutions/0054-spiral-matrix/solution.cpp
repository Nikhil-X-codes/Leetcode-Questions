class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        int st_row = 0, end_row = m - 1;
        int st_col = 0, end_col = n - 1;

        while (st_row <= end_row && st_col <= end_col) {

            for (int j = st_col; j <= end_col; ++j)
                res.push_back(matrix[st_row][j]);
            ++st_row;

            for (int i = st_row; i <= end_row; ++i)
                res.push_back(matrix[i][end_col]);
            --end_col;

            if (st_row <= end_row) {
                for (int j = end_col; j >= st_col; --j)
                    res.push_back(matrix[end_row][j]);
                --end_row;
            }

            if (st_col <= end_col) {
                for (int i = end_row; i >= st_row; --i)
                    res.push_back(matrix[i][st_col]); 
                ++st_col;
            }
        }

        return res;
    }
};

