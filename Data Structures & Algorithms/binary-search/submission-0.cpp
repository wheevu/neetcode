class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Since the array is sorted, compare target to middle element
        // if less, compare mid again to left portion, vice versa for right
        // rinse and repeat baby
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // overflow thing (ball knowledge)
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};