bool match(char *s, char *goal) {
    while (*s && *goal && *s == *goal) {
        ++s;
        ++goal;        
    }

    return (*goal == '\0');
}

bool rotateString(char* s, char* goal) {
    int len = strlen(s);

    // ensure the strings have the same length
    if (len != strlen(goal)) {
        return false;
    }
    
    // double the string
    int len_ = 2 * len;
    char *s_ = (char *) malloc((len_ + 1) * sizeof(char));

    memcpy(s_, s, len * sizeof(char));
    memcpy(s_ + len, s, len * sizeof(char));
    s_[len_] = '\0';

    // verify if goal is a substring
    // of the doubled string
    for (int i = 0; i < len_ - len; ++i) {
        if (match(s_ + i, goal)) {
            return true;
        }
    }

    return false;
}