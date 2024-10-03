bool checkDistances(char* s, int* distance, int distanceSize) {
    // compute the length of the string
    unsigned length = strlen(s);

    for (; *s; ++s, --length) {
        char c = *s;

        // verify if the character has already been visited
        if (c < 0) {
            continue;
        }

        // ensure the distance between equal characters
        // is as expected
        unsigned char index = distance[c - 'a'] + 1;

        if (index >= length || s[index] != c) {
            return false;
        }

        s[index] = -1; // set the character as visited
    }

    return true;
}