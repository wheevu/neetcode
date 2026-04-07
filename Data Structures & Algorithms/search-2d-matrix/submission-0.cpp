class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // yeah this one is basically binary search wearing a fake mustache
        // the 2D matrix can be reimagined into a long array (1D)

        // get matrix dimensions
        int rows = matrix.size();
        int cols = matrix[0].size();

        // search boundaries for the temu array
        int left = 0;
        int right = rows * cols - 1;

        // do da search
        // fun fact, I hang my clothes like this. TMI?
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // voodoo magic
            // row get "how many full rows there are before the mid index"
            // col get "how many elements there are before the mid index"
            // col does this by MODULO-ing the full rows before the mid index and           
            // get the remainders. Those remainders are the elements leading up to mid index.
            int row = mid / cols;
            int col = mid % cols;

            int value = matrix[row][col];

            // classic binary search
            if (value == target) {
                return true;
            } else if (value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};