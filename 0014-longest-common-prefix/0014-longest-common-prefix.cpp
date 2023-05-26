class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int min = 201;

        for (const string& str : strs)
            min = (str.size() < min) ? str.size() : min;

        for (int i = 0; i < min; ++i){
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); ++j){
                if (strs[j][i] == c) continue;
                return res;
            }

            res += c;
        }

        return res;
    }
};