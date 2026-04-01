class Solution {
public:
    bool isAnagram(string s, string t) {
        // if string s and t has different lengths -> false
        if (s.length() != t.length()) return false;

        // create map counting number of characters
        unordered_map<char, int> count;

        // loop over string s to count the char, subtract from string i with the char
        for (int i = 0; i < s.length(); i++){
            // these should work on the same char if string is an anagram
            count[s[i]]++;
            count[t[i]]--;

        }
 
        // if the char check is non zero, return false
        for (auto& pair : count){
            if (pair.second != 0) return false;
        }

        // pass everything -> return true
        return true;
  
    }
};
