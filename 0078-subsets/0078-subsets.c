/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int acc = 2 << (numsSize - 1); // the number of possible subsets
    
    // initialize the answer
    int **ans = malloc(acc * sizeof(int*));

    *returnSize = acc;
    *returnColumnSizes = malloc(acc * sizeof(int));

    // compute the subsets
    // O(2^n)
    while (acc--) {
        int acc_ = acc;

        // initialize the current subset
        int *subset = malloc(acc * sizeof(int));
        int subsetSize = 0;

        // determine the elements that belong in the current subset
        for (int i = 0; acc_; ++i) {
            _Bool bit = acc_ & 1;
            acc_ >>= 1;

            // only add elements whose index corresponds
            // to a bit 1 in the counter
            if (bit) {
                subset[subsetSize++] = nums[i];
            }
        }

        // append the subset to the answer
        ans[acc] = subset;
        (*returnColumnSizes)[acc] = subsetSize;
    }

    return ans;    
}