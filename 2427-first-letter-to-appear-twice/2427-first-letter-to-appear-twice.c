char repeatedCharacter(char* s) {
    bool letters[26];

    for (; *s; ++s) {
        char c = *s, index = c - 'a';

        // verify if the current letter has already appeared
        if (letters[index]) {
            return c;
        }

        ++letters[index];
    }

    // this will not be reached
    return 0;
}