class Solution {
public:
    int lengthOfLastWord(string s) {
        auto it = s.rbegin();

        // skip the spaces
        while (*it == ' ') { ++it; }

        // count the characters
        int acc = 0;

        while (*it && *it != ' ') {
            ++acc; ++it;
        }

        return acc;
    }
};