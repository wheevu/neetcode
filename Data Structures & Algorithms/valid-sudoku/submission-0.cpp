class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Hashing / Constraint checking
        // Check every box if a number (1 to 9) is in that row, column or 3x3 box.
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // coordinate
                char val = board[r][c];

                // ignore empty cells
                if (val == '.') continue;

                // map to box index (box 1, box 2,... box 9)
                int box = (r / 3) * 3 + (c / 3);

                // check for dups
                if (rows[r].count(val) || cols[c].count(val) || boxes[box].count(val)) {
                    return false;
                }

                // market digit as seen in the row, column and box.
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box].insert(val);
            }
        }

        return true;

    }
};
