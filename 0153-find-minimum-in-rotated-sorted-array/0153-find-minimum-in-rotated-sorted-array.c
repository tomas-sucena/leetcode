int findMin(int* nums, int numsSize) {
    int lower = 0, upper = numsSize - 1;

    while (nums[lower] > nums[upper]) {
        int middle = (lower + upper) / 2;

        if (nums[middle] < nums[lower]) {
            upper = middle;
        }
        else {
            lower = middle + 1;
        }
    }

    return nums[lower];
}