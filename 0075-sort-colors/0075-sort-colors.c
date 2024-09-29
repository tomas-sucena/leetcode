void sortColors(int* nums, int numsSize) {
    // place the 0s at the beginning of the array
    int left, right;

    for (left = 0; left < numsSize && nums[left] == 0; ++left);

    for (right = left + 1; right < numsSize && left < numsSize;) {
        // swap the elements
        if (nums[right] == 0) {
            int temp = nums[left];
            nums[left++] = 0;
            nums[right] = temp;
        }
        else {
            ++right;
        }
    }

    // place the 2s at the end of the array
    for (right = numsSize; left < right;) {
        // swap the elements
        if (nums[left] == 2) {
            int temp = nums[--right];
            nums[right] = 2;
            nums[left] = temp;
        }
        else {
            ++left;
        }
    }
}