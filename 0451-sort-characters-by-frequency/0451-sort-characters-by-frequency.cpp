class Solution {
public:
    string frequencySort(string s) {
        // count the number of occurrences
        std::unordered_map<char, int> letters;

        for (char c : s)
            ++letters[c];

        // order the characters by frequency
        std::vector<std::pair<char, int>> freq(letters.begin(), letters.end());
        sort(freq.begin(), freq.end(), [](auto &p1, auto &p2) {return p1.second > p2.second;} );

        // form the result string
        std::string res;
        
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            for (int i = 0; i < it->second; ++i)
                res += it->first;
        }

        return res;
    }
};