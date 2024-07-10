class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for (auto &log : logs) {
            if (log == "./") {
                continue;
            }

            ans = (log == "../") ? std::max(ans - 1, 0)
                                 : ans + 1;
        }
        
        return ans;
    }
};