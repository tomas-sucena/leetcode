int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    _Bool repeated = 0;

    for (int i = 1; i < numsSize; ++i) {
        // verify if the current number equals the previous
        if (nums[i] != nums[k]) {
            nums[++k] = nums[i];
            repeated = 0;
        }
        else if (!repeated) {
            nums[++k] = nums[i];
            repeated = 1;
        }
    }

    return k + 1;
}