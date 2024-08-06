bool isPalindrome(char* s) {
    // get a pointer to the end of the string    
    const char *s_ = s + strlen(s) - 1;

    // determine if the string is a palindrome
    // by iteratively comparing the front and back characters
    while (s < s_) {
        // NOTE: 32 = 'a' - 'A'
        char c = *s;
        c -= (c >= 'a') * 32;

        char c_ = *s_;
        c_ -= (c_ >= 'a') * 32;

        // verify if the characters are the same
        if (c == c_) {
            ++s; --s_;
            continue;
        }

        _Bool alphanumeric = 1;

        // verify if the front character is alphanumeric
        if ((c < 'A' || c > 'Z') && (c < '0' || c > '9')) {
            ++s;
            alphanumeric = 0;
        }

        // verify if the back character is alphanumeric
        if ((c_ < 'A' || c_ > 'Z') && (c_ < '0' || c_ > '9')) {
            --s_;
            alphanumeric = 0;
        }
        
        if (alphanumeric) {
            return false;
        }
    }

    return true;
}