int strStr(char* haystack, char* needle) {
    for (int index = 0; haystack[index]; ) {
        int nextIndex = index;
        _Bool advanceIndex = 1;

        // attempt to find a match
        const char *needle_ = needle;

        for (int i = index; haystack[i] && *needle_ == haystack[i]; ++i) {
            ++needle_;

            nextIndex += advanceIndex;
            advanceIndex &= (haystack[i] != *needle);
        }

        // verify if a match was found
        if (*needle_ == '\0') {
            return index;
        }

        index = nextIndex + (nextIndex == index);
    }

    return -1;
}