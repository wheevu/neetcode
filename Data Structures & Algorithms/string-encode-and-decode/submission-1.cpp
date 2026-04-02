class Solution {
public:
    string encode(vector<string>& strs) {
        string result;

        // ranged loop to store strings in the vector of strings
        for (string& str : strs) {
            // sending a string with format: (length)#(content)
            // first iteration example: result = "5#Hello"
            // second iteration example: reult = "5#Hello5#World"
            // to_string ---(much later)-----> stoi()
            result += to_string(str.length()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;


        // start i loop over s length
        while (i < s.length()) {
            int j = i;

            // j loop go until reaches #
            while (s[j] != '#') {
                j++;
            }

            // ## Handle the Length
            // j is at #, substring from i to (j - 1) is the length (i.e. '5')
            // s.substr(start, end) -> "5"
            // stoi() -> string to int
            int length = stoi(s.substr(i, j - i));

            // ## Handle the Content
            string word = s.substr(j + 1, length);

            // insert word content to result
            result.push_back(word);

            // Go pass # and the finished word, get ready for next word
            i = j + 1 + length;
        }

        return result;
    }
};