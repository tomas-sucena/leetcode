#define MAX(a, b) ((a > b) ? a : b)

int longestSubarray(int* nums, int numsSize) {
    int maxLength = 0, maxNum = -1;

    for (int i = 0; i < numsSize; ) {
        int curr = nums[i++];

        // compute the length of the subarray
        int length = 1;

        for (; i < numsSize && nums[i] == curr; ++i) {
            ++length;
        }

        // if the current number is greater than the maximum,
        // unconditionally replace the maximum length
        if (curr > maxNum) {
            maxLength = length;
            maxNum = curr;
        }
        // if the current number is equal to the maximum,
        // update the maximum length only if the current length is greater than it
        else if (curr == maxNum) {
            maxLength = MAX(length, maxLength);
        }
    }

    return maxLength;
}
