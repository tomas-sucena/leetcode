class Solution {
    string rleEncode(string num) {
        string rle;

        for (auto it = num.begin(); *it; ) {
            char acc = '1';
            char curr = *it++;

            while (*it == curr) {
                ++acc; ++it;

                // ensure the accumulator does not exceed 9
                if (acc == '9') {
                    break;
                }
            }

            rle.push_back(acc);
            rle.push_back(curr);
        }

        return rle;
    }

public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        return rleEncode(countAndSay(n - 1));
    }
};