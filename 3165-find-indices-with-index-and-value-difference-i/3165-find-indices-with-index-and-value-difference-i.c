int abs(int a) {
    return a > 0
        ? a
        : -a;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize) {
    int *ans = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize - indexDifference; ++i) {
        for (int j = i + indexDifference; j < numsSize; ++j) {
            if (abs(nums[i] - nums[j]) >= valueDifference) {
                ans[0] = i; ans[1] = j;
                return ans;
            }
        }
    }

    // no pair of indices meets the requirements
    ans[0] = ans[1] = -1;
    return ans;
}