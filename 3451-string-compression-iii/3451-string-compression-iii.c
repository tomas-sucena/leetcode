char* compressedString(char* word) {
    // initialize the compressed string
    char *comp = malloc((2 * strlen(word) + 1) * sizeof(char)),
        *temp = comp;

    while (*word) {
        char c = *word++;
        char count = '1';

        // count the number of successive equal characters
        while (*word == c && count < '9') {
            ++word;
            ++count;
        }

        *temp++ = count; // append the number
        *temp++ = c; // append the character
    }

    *temp = '\0';
    return comp;
}