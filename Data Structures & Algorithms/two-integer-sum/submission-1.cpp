class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make map
        unordered_map<int, int> seen;

        // loop over vector
        // make complement from target and current element
        // look for the complement number in map -> return the answer if it's there
        // CAN'T INSERT FIRST: if inserted first, then checked after,  could accidentally match the current number with itself.
        // insert the current element

        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()){
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }
        
        // return vector (empty) because the function requires it
        return {};
    }

    
};
