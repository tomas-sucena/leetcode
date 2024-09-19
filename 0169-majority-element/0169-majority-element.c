int lessThan(const void *a, const void *b) {
    return (*(int*) a) - (*(int*) b);
}

int majorityElement(int* nums, int numsSize) {
    // sort the array
    qsort(nums, numsSize, sizeof(int), lessThan);

    // return the middle element
    return nums[numsSize / 2];
}