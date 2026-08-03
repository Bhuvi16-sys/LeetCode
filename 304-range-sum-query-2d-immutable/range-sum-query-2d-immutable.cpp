#include <vector>

class NumMatrix {
private:
    std::vector<std::vector<int>> pref;

public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Size padding (rows + 1) x (cols + 1) to avoid boundary checking
        pref.assign(rows + 1, std::vector<int>(cols + 1, 0));
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                pref[r + 1][c + 1] = matrix[r][c] 
                                   + pref[r][c + 1] 
                                   + pref[r + 1][c] 
                                   - pref[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Inclusion-Exclusion Principle formula
        return pref[row2 + 1][col2 + 1] 
             - pref[row1][col2 + 1] 
             - pref[row2 + 1][col1] 
             + pref[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */