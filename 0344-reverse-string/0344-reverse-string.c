void reverseString(char* s, int sSize) {
    char *s_ = s + sSize; // pointer to the back of the string

    for (char c = *s; s < --s_; c = *s) {
        *s++ = *s_;
        *s_ = c;
    }
}