class Solution {
public:
    int romanToInt(string s) {
        // special case
        if (s.empty()) return 0;

        unordered_map<char, int> toRoman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int res = toRoman[s.back()];
        for (int i = 0; i < s.size() - 1; ++i){
            if (toRoman[s[i]] >= toRoman[s[i + 1]]){
                res += toRoman[s[i]];
                continue;
            }

            res -= toRoman[s[i]];
        }
        
        return res;
    }
};