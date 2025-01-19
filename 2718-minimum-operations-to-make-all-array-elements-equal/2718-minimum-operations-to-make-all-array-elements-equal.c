int lessThan(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}

int binarySearch(int *nums, int numsSize, int target) {
    int lower = 0, upper = numsSize;

    while (lower < upper) {
        int middle = (lower + upper) / 2;

        if (nums[middle] > target) {
            upper = middle;
        }
        else {
            lower = middle + 1;
        }
    }

    return lower;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* minOperations(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    // sort the array
    qsort(nums, numsSize, sizeof(int), lessThan);

    // compute the prefix sums of all elements
    // starting from the front and back
    long long *sums = (long long *) calloc(numsSize + 1, sizeof(long long));
    long long prev = sums[1] = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        sums[i + 1] = (prev += nums[i]); 
    }

    // initialize the answer
    long long *ans = (long long *) malloc(queriesSize * sizeof(long long));
    *returnSize = queriesSize;

    // solve the queries
    for (int i = 0; i < queriesSize; ++i) {
        long long target = queries[i];
        long long index = binarySearch(nums, numsSize, target);

        ans[i] = (target * index - sums[index]) // < target
            + ((sums[numsSize] - sums[index]) - target * (numsSize - index)); // > target
    }

    return ans;
}