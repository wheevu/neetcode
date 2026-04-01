class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            // check if num is in seen
            if (seen.find(num) != seen.end()){
                return true;
            }

            seen.insert(num);
        }

        return false;
    }

};