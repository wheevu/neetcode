class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums){
            freq[num]++;
        }

        vector<pair<int, int>> arr;

        for (auto& pair : freq){
            arr.push_back({pair.second, pair.first});
        }

        vector<int> result;

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        for (int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }
        
        return result;
    }
};
