bool areAlmostEqual(char* s1, char* s2) {
    bool canSwitch = true;
    char diff1 = -1, diff2 = -1; // to store the characters that differ

    for (; *s1; ++s1, ++s2) {
        if (*s1 == *s2) {
            continue;
        }
        else if (canSwitch) {
            diff1 = *s1; diff2 = *s2;
            canSwitch = false;
        }
        else if (*s1 != diff2 || *s2 != diff1) {
            return false;
        }
        else {
            diff1 = diff2 = -1;
        }
    }

    return diff1 < 0;
}