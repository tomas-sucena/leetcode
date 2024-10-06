char* reverseWords(char* s) {
    int length = strlen(s);
    char *s_ = s + length - 1; // pointer to the back of the string

    // initialize the answer
    char *ans = malloc((length + 1) * sizeof(char));
    char *ans_ = ans; // pointer to the back of the answer

    for (;;) {
        // ignore trailing spaces
        for (; s < s_ && *s_ == ' '; --s_);

        // determine the length of the next word
        int wordLength = 0;
        for (; s <= s_ && *s_ != ' '; --s_, wordLength++);

        // verify if we have reached the end of the string
        if (wordLength == 0) {
            break;
        }

        // copy the next word to the answer
        memcpy(ans_, s_ + 1, wordLength * sizeof(char));
        ans_ += wordLength;

        // add a space to the answer
        *ans_++ = ' ';
    }

    ans_[-1] = '\0';
    return ans;
}