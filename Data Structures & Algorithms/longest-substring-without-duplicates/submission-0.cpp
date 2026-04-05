class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // set, left pointer, longest (the result)
        unordered_set<char> window;
        int left = 0;
        int longest = 0;

        // loop over string
        // while loop: if rightmost char is in set, remove char from left
        // removing char from left (to add right char to the substring)
        // this is to make sure we don't break the substring (continuous chars)
        // add right char
        // update longest
        for (int right = 0; right < s.length(); right++) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};