// reads the next number in a string
// and advances the string pointer
unsigned getNumber(char **strPtr) {
    unsigned number = 0;
    char *str = *strPtr;

    for (; *str && *str != '.'; ++str) {
        number = number * 10 + (*str - '0');
    }

    *strPtr = str + (*str == '.');
    return number;
}

int compareVersion(char* version1, char* version2) {
    // compare the strings until both have no revisions left
    while (*version1 || *version2) {
        // compare the revisions
        int diff = getNumber(&version1) - getNumber(&version2);

        if (diff < 0) {
            return -1;
        }
        else if (diff > 0) {
            return 1;
        }
    }

    // the strings are the same
    return 0;
}