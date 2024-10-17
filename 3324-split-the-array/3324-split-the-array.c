int lessThan(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}

bool isPossibleToSplit(int* nums, int numsSize) {
    // sort the array
    qsort(nums, numsSize, sizeof(int), lessThan);

    // ensure all numbers with even index are unique
    int prev = -1;

    for (int i = 0; i < numsSize; i += 2) {
        if (nums[i] == prev) {
            return false;
        }

        prev = nums[i];
    }

    // ensure all numbers with odd index are unique
    prev = -1;

    for (int i = 1; i < numsSize; i += 2) {
        if (nums[i] == prev) {
            return false;
        }

        prev = nums[i];
    }

    return true;
}