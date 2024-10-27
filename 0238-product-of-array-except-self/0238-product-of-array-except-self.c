/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // initialize the answer
    int *ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // compute the prefixes
    int prod = 1;

    for (int i = 0; i < numsSize; ++i) {
        ans[i] = prod;
        prod *= nums[i];
    }

    // compute the suffixes
    prod = 1;

    for (int i = numsSize - 1; i >= 0; --i) {
        ans[i] *= prod;
        prod *= nums[i];
    }

    return ans;
}