bool isArraySpecial(int* nums, int numsSize) {
    int prev = nums[0];

    // ensure each pair of adjacent elements
    // have different parity
    for (int i = 1; i < numsSize; ++i) {
        int curr = nums[i];

        if ((prev & 1) == (curr & 1)) {
            return false;
        }

        prev = curr;
    }

    return true;
}