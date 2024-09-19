void rotate(int* nums, int numsSize, int k) {
    int *temp = malloc(numsSize * sizeof(int));
    k %= numsSize;

    // iterate through the original array and place the elements
    // in their respective places in the rotated array
    int index = numsSize - k;

    for (int i = 0; i < numsSize; ++i) {
        temp[i] = nums[index++ % numsSize];
    }

    // switch the original array with the rotated array
    memcpy(nums, temp, numsSize * sizeof(int));

    // free the temporary array
    free(temp);
}