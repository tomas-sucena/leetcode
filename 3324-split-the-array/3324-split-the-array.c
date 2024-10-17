bool isPossibleToSplit(int* nums, int numsSize) {
    unsigned char occurrences[101];

    // ensure all elements appear at most twice
    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];

        if (++occurrences[num] > 2) {
            return false;
        }
    }

    return true;
}