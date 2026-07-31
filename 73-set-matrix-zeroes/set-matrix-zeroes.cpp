class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstColZero = false;

        // Step 1: Mark the first row and column as indicators
        for (int r = 0; r < row; r++) {
            if (matrix[r][0] == 0) {
                firstColZero = true;
            }
            for (int c = 1; c < col; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Step 2: Update the inner matrix based on indicators
        for (int r = 1; r < row; r++) {
            for (int c = 1; c < col; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 3: Zero out the first row if needed
        if (matrix[0][0] == 0) {
            for (int c = 0; c < col; c++) {
                matrix[0][c] = 0;
            }
        }

        // Step 4: Zero out the first column if needed
        if (firstColZero) {
            for (int r = 0; r < row; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};