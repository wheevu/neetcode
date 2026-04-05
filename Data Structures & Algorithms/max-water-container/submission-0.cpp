class Solution {
public:
    int maxArea(vector<int>& heights) {
        // initialize two pointers left, right, and maxWater area.
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = 0;

        // while loop for left < right
        // initialize width, height, area
        // update maxWater with area
        // move either left or right inwards depending on which one is smaller (avoids double loop brute force)
        while (left < right) {
            int width = right - left;
            int h = min(heights[left], heights[right]);
            int area = width * h;

            maxWater = max(maxWater, area);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};