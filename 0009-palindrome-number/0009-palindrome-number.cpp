class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        long rev = 0;
        for (long i = x; i > 0; i /= 10){
            rev *= 10;
            rev += i % 10;
        }
              
        return (x == rev);
    }
};