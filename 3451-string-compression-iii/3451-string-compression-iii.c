char* compressedString(char* word) {
    // initialize the compressed string
    char *comp = malloc((2 * strlen(word) + 1) * sizeof(unsigned char)),
        *temp = comp;

    while (*word) {
        char c = *word++;
        int count = 1;

        // count the number of successive equal characters
        while (*word == c && count < 9) {
            ++word;
            ++count;
        }

        *temp++ = count + '0'; // append the number
        *temp++ = c; // append the character
    }

    *temp = '\0';
    return comp;
}