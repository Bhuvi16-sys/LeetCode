class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rowSeen[i][num] || colSeen[j][num] || boxSeen[boxIndex][num]) {
                    return false;
                }

                rowSeen[i][num] = true;
                colSeen[j][num] = true;
                boxSeen[boxIndex][num] = true;
            }
        }

        return true;
    }
};