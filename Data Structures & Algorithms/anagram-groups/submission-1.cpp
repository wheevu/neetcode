class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // make map with a string as key and a group of strings as element
        unordered_map <string, vector<string>> groups;

        // loop over string strs
        // sort s as string key
        // add string s with string key to map
        for (string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        // make vector containing vectors of string -> result
        vector <vector<string>> result;
        
        // loop pair (key, element) over map -> add the elements of pair to result vector
        for (auto& pair : groups){
            result.push_back(pair.second);
        }
        // return result

        return result;
    }
};