#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++){
            int current = target - nums[i];

            if (seen.find(current) != seen.end()){
                return {seen[current], i};
        }

            seen[nums[i]] = i;
        }
        return {};
    }

    
};
