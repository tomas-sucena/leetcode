class Solution {
private:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno",
                              "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        auto dit = digits.begin();

        // parse the first letter
        for (char c : letters[*dit - '2'])
            res.push_back({c});
            
        // parse remaining letters
        while (++dit != digits.end()) {
            std::vector<string> temp;

            for (const string &s : res) {
                for (char c : letters[*dit - '2'])
                    temp.push_back(s + c);
            }

            res = temp;
        }
        
        return res;
    }
};