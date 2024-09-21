class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
    if (original.size() != m * n) {
            return {};  // Return an empty array if conversion is not possible
        }
        
        vector<vector<int>> result(m, vector<int>(n));  // Create m x n matrix
        
        for (int i = 0; i < original.size(); i++) {
            int row = i / n;  // Calculate row index
            int col = i % n;  // Calculate column index
            result[row][col] = original[i];  // Place the value from 1D array into the 2D array
        }
        
        return result;
        
    }
};
