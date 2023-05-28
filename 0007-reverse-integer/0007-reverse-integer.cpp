class Solution {
private:
    bool overflow(int a, int b) {
        return ((a > 0) ^ (b > 0)) 
            ? (a < INT_MIN / b) 
            : (a > INT_MAX / b);
    }

public:
    int reverse(int x) {
        int rev = 0;
        
        for (; x; x /= 10) {
            if (overflow(rev, 10))
                return 0;

            rev *= 10;
            rev += x % 10;
        }

        return rev;
    }
};