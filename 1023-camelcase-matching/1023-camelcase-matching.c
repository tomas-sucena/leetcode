bool match(char *query, char *pattern) {
    for (; *query && *pattern; ++query) {
        if (*query == *pattern) {
            ++pattern;
        }
        else if (isupper(*query)) {
            return false;
        }
    }

    // ensure no more uppercase characters appear
    for (; *query; ++query) {
        if (isupper(*query)) {
            return false;
        }
    }

    return *pattern == '\0';
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    // initialize the answer
    bool *ans = malloc(queriesSize * sizeof(bool));
    *returnSize = queriesSize;

    // verify if the queries match the pattern
    for (int i = 0; i < queriesSize; ++i) {
        ans[i] = match(queries[i], pattern);
    }

    return ans;
}