class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;

        string res;
        int row = 0, temp = (numRows - 1) * 2;
        
        // top row
        for (int j = row; j < s.size(); j += temp)
            res += s[j];
        
        // middle rows
        for (++row; row < numRows - 1; ++row) {
            int step = row * 2;

            for (int j = row; j < s.size(); j += step) {
                res += s[j];
                step = temp - step;
            }
        }

        // bottom row
        for (int j = row; j < s.size(); j += temp)
            res += s[j];
        
        return res;
    }
};