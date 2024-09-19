void rotate(int* nums, int numsSize, int k) {
    // compute the minimum number of shifts required
    k %= numsSize;

    if (k == 0) {
        return;
    }
    
    // save the last k elements
    int k_ = numsSize - k, cache[k %= numsSize];
    memcpy(cache, nums + k_, k * sizeof(int));

    // shift the array k steps to the right
    for (int i = 0; i < k_;) {
        nums[--numsSize] = nums[k_ - ++i];
    }

    // place the original last k elements in the beginning
    memcpy(nums, cache, k * sizeof(int));
}