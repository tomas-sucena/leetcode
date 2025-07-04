int possibleStringCount(char* word) {
    int ans = 1;

    while (*word) {
        char curr = *word++;

        for (; *word == curr; ++word) {
            ++ans;
        }
    }

    return ans;
}