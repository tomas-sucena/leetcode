int min(int a, int b) {
    return (a < b)
        ? a
        : b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int *missingRolls = malloc(n * sizeof(int));

    // compute the required sum of the n observations
    int sum = mean * (n + rollsSize);

    for (int i = 0; i < rollsSize; ++i) {
        sum -= rolls[i];
    }

    // determine if the sum is achievable with n rolls
    int roll = sum / n;
    
    if (6 * n < sum || roll <= 0) {
        *returnSize = 0;
        return missingRolls;
    }

    // fill the missing rolls with the division of the sum by n
    sum -= n * roll;
    
    for (int i = 0; i < n; ++i) {
        missingRolls[i] = roll;
    }
    
    *returnSize = n;

    // if the sum is still not zero, boost the lower rolls
    while (sum > 0) {
        int remaining = 6 - missingRolls[--n];
        
        missingRolls[n] += min(sum, remaining);
        sum -= remaining;
    }

    return missingRolls;
}