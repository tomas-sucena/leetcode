bool isPrefixAndSuffix(char *str1, char *str2) {
    // verify if the first word is a prefix of the second
    int len = 0;

    while (*str1 && *str2 && *str1 == *str2) {
        ++str1; ++str2;
        ++len;
    }

    if (*str1) {
        return false;
    }

    // advance to the end of the second word
    while (*str2) {
        ++str2;
    }

    // verify if the first word is a suffix of the second
    while (len && *--str1 == *--str2) {
        --len;
    }

    return (len == 0);
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int ans = 0;

    for (int i = 0; i < wordsSize; ++i) {
        for (int j = i + 1; j < wordsSize; ++j) {
            ans += isPrefixAndSuffix(words[i], words[j]);
        }
    }

    return ans;
}