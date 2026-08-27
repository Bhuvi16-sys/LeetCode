#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Fill first row (can only come from the left)
        for (int col = 1; col < cols; col++) {
            grid[0][col] += grid[0][col - 1];
        }

        // 2. Fill first column (can only come from above)
        for (int row = 1; row < rows; row++) {
            grid[row][0] += grid[row - 1][0];
        }

        // 3. Fill the rest of the grid
        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }

        return grid[rows - 1][cols - 1];
    }
};