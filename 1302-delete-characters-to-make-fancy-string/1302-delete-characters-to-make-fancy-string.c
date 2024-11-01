char* makeFancyString(char* s) {
    // initialize the answer
    char *ans = malloc((strlen(s) + 1) * sizeof(char)),
         *temp = ans;

    // remove characters that appear thrice in a row
    char prev = '\0';
    int acc;

    for (; *s; ++s) {
        char curr = *s;

        if (curr != prev) {
            acc = 1; // reset the counter
        }
        else if (++acc > 2) {
            continue;
        }
        
        // append the character to the answer
        *temp++ = prev = curr;
    }

    *temp = '\0';
    return ans;
}