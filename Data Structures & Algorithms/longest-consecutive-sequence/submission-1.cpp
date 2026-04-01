class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // voodoo magic
        unordered_set <int> arr(nums.begin(), nums.end());
        int longest = 0;

        for (int num : arr){
            if (arr.find(num - 1) == arr.end()){
                int current = num;
                int streak = 1;

                while (arr.find(current + 1) != arr.end()){
                    current++;
                    streak++;
                }

                // update longest when streak is higher
                longest = max(longest, streak);
                    
            }

        }

        return longest;
    }
};


