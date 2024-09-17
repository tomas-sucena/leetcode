bool isCapitalLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

bool detectCapitalUse(char* word) {
    // the first letter is NOT a capital letter
    if (!isCapitalLetter(*word) || !isCapitalLetter(*++word)) {
        // ensure the rest of the word is not capitalized
        for (; *word; ++word) {
            if (isCapitalLetter(*word)) {
                return false;
            }
        }

        return true;
    }

    // the first two letters are capitalized,
    // ensure all are capitalized
    for (; *word; ++word) {
        if (!isCapitalLetter(*word)) {
            return false;
        }
    }

    return true;
}