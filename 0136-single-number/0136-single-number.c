int singleNumber(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; ++i) {
        // NOTE: x ^ x = 0, which means that all duplicate elements
        // will cancel each other out.
        ans ^= nums[i];
    }

    return ans;
}