#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        // hashmap
        unordered_map<char, int> romanNum = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // add the first roman number to the right
        int result = romanNum[s[s.length() - 1]];

        // start loop at the second rightmost
        // (s.length() - 1) is rightmost
        for (int i = s.length() - 2; i >= 0; i--){
            // check if current symbol is smaller to symbol to the right
            // if smaller (e.g. 'IV') -> subtract current symbol (i.g. 'I');
            if (romanNum[s[i]] < romanNum[s[i + 1]]) {
                result -= romanNum[s[i]];
            }
            
            // VI -> add current symbol (V)
            else {
                result += romanNum[s[i]];
            }
        }
        return result; 
    }
};