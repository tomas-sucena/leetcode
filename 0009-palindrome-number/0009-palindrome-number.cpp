class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        string normal, reverse;
        for (; x > 0; x /= 10){
            char c = char(x % 10);

            normal += c;
            reverse = c + reverse;
        }
        
        return (normal == reverse);
    }
};