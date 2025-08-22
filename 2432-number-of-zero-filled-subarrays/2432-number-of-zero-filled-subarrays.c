long long zeroFilledSubarray(int* nums, int numsSize) {
    long long ans = 0;

    for (int i = 0; i < numsSize; ) {
        // count the number of consecutive zeros
        long long zeros = 0;
        for (; i < numsSize && nums[i++] == 0; ++zeros);

        // calculate the number of subsequences
        if (zeros) {
            ans += (1 + zeros) * (zeros / 2) + (zeros % 2) * ((zeros + 1) / 2);
        }
    }

    return ans;
}

/** OPTIMAL SOLUTION
long long zeroFilledSubarray(int* nums, int numsSize) {
    long long ans = 0;
    int zeros = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i]) {
            zeros = 0;
        }
        else {
            ans += ++zeros;
        }
    }

    return ans;
}
*/
