int strStr(char* haystack, char* needle) {
    int index = 0;

    for (; *haystack; ++index) {
        char *haystack_ = haystack++;
        char *needle_ = needle;

        while (*haystack_ && *needle_ == *haystack_) {
            ++needle_; ++haystack_;
        }

        // verify if a match was found
        if (*needle_ == '\0') {
            return index;
        }
    }

    return -1;
}