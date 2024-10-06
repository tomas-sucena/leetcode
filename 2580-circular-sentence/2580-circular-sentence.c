// O(n)
bool isCircularSentence(char* sentence) {
    char *curr = sentence;

    // read the first word
    for (; *curr && *curr != ' '; ++curr);
    char prev = curr[-1];

    while (*curr) {
        // verify if the last character of a word
        // is the first character of the next
        if (prev != *++curr) {
            return false;
        }

        // read the next word
        for (; *curr && *curr != ' '; ++curr);
        prev = curr[-1];
    }

    // ensure the last character equals the first
    return *sentence == curr[-1];
}