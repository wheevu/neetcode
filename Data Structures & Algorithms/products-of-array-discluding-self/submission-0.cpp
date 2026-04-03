class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // ## Idea: for every index position, do a pass of every product before/after and combine them
        // Ex: [1,2,4,6] -> first pass (from left): [1,1,2,8], second pass (from right): [42,24,6,1]
        // (if there's nothing before/after, use '1')
        // Combine: 1*42, 2*24, 4*6, 6*1

        int n = nums.size();
        // make vector the size of n, filled with 1s (as to cover the edge indices)
        vector<int> answer(n, 1);

        // First pass: store prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Second pass: multiply by suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};