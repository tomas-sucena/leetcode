char* addSpaces(char* s, int* spaces, int spacesSize) {
    // initialize the answer
    int strSize = strlen(s);
    char *ans = (char *) malloc((strSize + spacesSize + 1) * sizeof(char));

    // iterate through the original string
    // and add the spaces when needed
    char *temp = ans;

    for (int i = 0; i < strSize; ++i) {
        // verify if a space needs to be added
        if (spacesSize > 0 && *spaces == i) {
            *temp++ = ' ';
            ++spaces; --spacesSize;
        }

        *temp++ = s[i];
    }

    *temp = '\0';
    return ans;
}