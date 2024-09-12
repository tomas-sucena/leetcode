int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    // determine which characters are allowed
    bool chars[26];

    for (; *allowed; ++allowed) {
        chars[*allowed - 'a'] = true;
    }

    // compute the consistent strings
    int acc = 0;

    for (int i = 0; i < wordsSize; ++i) {
        bool consistent = true;

        for (char *word = words[i]; *word; ++word) {
            if (!chars[*word - 'a']) {
                consistent = false;
                break;
            }
        }

        acc += consistent;
    }

    return acc;
}