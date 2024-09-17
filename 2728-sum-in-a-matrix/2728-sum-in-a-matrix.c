int greaterThan(const void *a, const void *b) {
    return (*(int*) b) - (*(int*) a);
}

int matrixSum(int** nums, int numsSize, int* numsColSize) {
    // sort the matrix rows descendingly
    for (int i = 0; i < numsSize; ++i) {
        qsort(nums[i], numsColSize[i], sizeof(int), greaterThan);
    }

    // compute the score
    int score = 0;

    for (int i = 0; i < *numsColSize; ++i) {
        int max = -1;

        for (int j = 0; j < numsSize; ++j) {
            if (max < nums[j][i]) {
                max = nums[j][i];
            }
        }

        score += max;
    }

    return score;
}