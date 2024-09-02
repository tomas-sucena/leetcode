int chalkReplacer(int* chalk, int chalkSize, int k) {
    // count the total amount of chalk required for all
    // students to solve their problems
    unsigned long totalChalk = 0;

    for (int i = 0; i < chalkSize; ++i) {
        totalChalk += chalk[i];
    }

    k %= totalChalk;
    int index;

    for (index = 0; index < chalkSize && k >= chalk[index]; ++index) {
        k -= chalk[index];
    }

    return index;
}