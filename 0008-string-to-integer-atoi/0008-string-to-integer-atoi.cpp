class Solution {
public:
    int myAtoi(string s) {
        long n = 0;
        bool negative = false;

        auto it = s.begin();

        // ignore whitespace
        while (it != s.end() && *it == ' ')
            ++it;

        if (it == s.end())
            return n;

        // check '+' and '-'
        if (*it == '+')
            ++it;
        else if (*it == '-') {
            negative = true;
            ++it;
        }

        // read digits
        for (; it != s.end() && *it >= '0' && *it <= '9'; ++it) {
            n = n * 10 + (*it - '0');

            // verify if clamping is necessary
            if (negative && n - 1 >= INT_MAX) {
                return INT_MIN;
            }
            else if (n >= INT_MAX) {
                return INT_MAX;
            }
        }

        return negative ? -n : n;
    }
};
