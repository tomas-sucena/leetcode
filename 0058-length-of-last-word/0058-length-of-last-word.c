int lengthOfLastWord(char* s) {
    int ans;

    for (;;) {
        // skip the spaces
        while (*s == ' ') { ++s; }

        if (*s == '\0') {
            break;
        }

        // count the characters
        ans = 0;
        
        while (*s && *s != ' ') {
            ++ans; ++s;
        }
    }

    return ans;
}