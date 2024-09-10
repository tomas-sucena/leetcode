int jump(int* nums, int numsSize) {
    int jumps = 0;
    --numsSize;

    for (int i = 0; i < numsSize; ++jumps) {
        // verify if we can reach the end from the current index
        if (i + nums[i] >= numsSize) {
            i += nums[i];
            continue;
        }

        // determine the entry with the highest value
        int nextIndex, maxValue = INT_MIN;

        for (int j = i + nums[i]; j > i; --j) {
            int value = j + nums[j] - numsSize;

            if (maxValue < value) {
                nextIndex = j;
                maxValue = value;
            }
        }

        i = nextIndex;
    }

    return jumps;
}