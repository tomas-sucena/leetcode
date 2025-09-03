char findTheDifference(char* s, char* t) {
    int letters[26];

    // create a pseudo hash set with the letters of string 's'
    for (; *s; ++s) {
        ++letters[*s - 'a'];
    }

    // find the extra letter
    for (; *t; ++t) {
        char c = *t;

        if (letters[c - 'a']-- == 0) {
            return c;
        }
    }

    return '\0'; // both words have the same letters
}