class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Idea: sort the array, run for loop at i, use pointers at (i + 1) and (n - 1) to check sum == 0
        // If sum < 0, it's too small -> left++ (left is smaller since we sorted)
        // If sum > 0, it's too big -> right-- (right is bigger since we sorted)
        // Skip duplicates

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // skip adjacent duplicate first numbers -> use 'continue' (skip the rest of the code if met condition)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } 
                else if (sum > 0) {
                    right--;
                } 
                else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // skip duplicate for second numbers
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // skip duplicate for third numbers
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};