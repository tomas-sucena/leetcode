int waysToSplitArray(int* nums, int numsSize) {
    // compute the first split
    long left = nums[0], right = nums[1];

    for (int i = 2; i < numsSize; ++i) {
        right += nums[i];
    }

    // determine the number of valid splits
    int ans = 0;

    for (int i = 0; i < numsSize - 1; ++i) {
        ans += (left >= right);

        // compute the next split
        int middle = nums[i + 1];

        left += middle;
        right -= middle;
    }

    return ans;
}