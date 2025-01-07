class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // order the words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        // initialize the answer
        std::vector<string> ans;

        // find all substrings
        for (auto it = words.begin(); it != words.end(); ++it) {
            const std::string &word = *it;

            for (auto rit = words.end() - 1; rit != it; --rit) {
                if (rit->find(word) != std::string::npos) {
                    ans.emplace_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};