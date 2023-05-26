class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, max = 0;
        unordered_set<char> letters;

        for (; i < (int) s.size(); ++i){
            char c = s[i];

            if (letters.insert(c).second)
                continue;

            max = std::max(max, i - j);

            while (s[j] != c)
                letters.erase(s[j++]);
            ++j;
        }

        return std::max(max, i - j);
    }
};