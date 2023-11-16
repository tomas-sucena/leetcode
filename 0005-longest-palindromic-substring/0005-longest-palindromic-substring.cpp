class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        std::vector<bool> palindromes(s.size() * s.size(), false);

        // state that all letters are palindromes
        for (int i = 0; i < s.size(); ++i)
            palindromes[i * s.size()] = true;
        
        // compute remaining palindromes
        for (int len = 1; len < s.size(); ++len) {
            for (int i = 0; i < s.size() - len; ++i) {
                int j = i + len;
                bool isPal = (s[i] == s[j]);

                int i_ = i + 1, j_ = j - 1;

                if (i_ < j_)
                    isPal &= palindromes[i_ * s.size() + j_];

                if (!isPal)
                    continue;

                start = i; end = j;
                palindromes[i * s.size() + j] = isPal;
            }
        }

        // get the palindrome
        string res;

        for (int i = start; i <= end; ++i)
            res += s[i];

        return res;
    }
};