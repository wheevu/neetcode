class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create map number -> frequency
        unordered_map<int, int> freq;

        // ## Count the frequencies
        // loop over every element of vector nums with int num
        // increase the count for the key in nums matching num; otherwise initialize it at 0
        for (int num : nums){
            freq[num]++;
        }

        // ## Make vector storing the {frequency, num} from map
        // create vector with pairs as elements
        // loop over every element PAIRS of map freq
        // add new pair to vector at the end; frequency first; number second;
        vector <pair<int, int>> arr;

        for (auto& pair : freq){
            arr.push_back({pair.second, pair.first});
        }


        // ## Sorting the vector from start to end by descending order

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        // ## Create answer vector - which is the k element with the highest frequencies 
        // add the number from the pair vector to the answer vector

        vector <int> result;
        
        for (int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }
            
        // ## Print result
        
        return result;
    }
};