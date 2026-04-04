class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        // two pointers problem
        // idea: normalize string then check each char

        while (left < right) {
            // isalum -> is alphanumeric (a-z, A-Z, 0-9) -> used to skip spaces and punctuation
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // tolower -> to lowercase
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};
