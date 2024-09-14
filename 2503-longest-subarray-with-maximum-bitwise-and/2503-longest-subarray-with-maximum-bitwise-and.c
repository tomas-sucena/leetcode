#define MAX(a, b) ((a > b) ? a : b)

int longestSubarray(int* nums, int numsSize) {
    int maxLength = 0, maxNum = -1;

    for (int i = 0; i < numsSize; ) {
        int curr = nums[i++];
                
        // if the current number is lower than the current
        // maximum bitwise AND, ignore it
        if (curr < maxNum) {
            continue;
        }

        // compute the length of the subarray
        int length = 1;

        for (; i < numsSize && nums[i] == curr; ++i) {
            ++length;
        }

        if (curr > maxNum) {
            maxLength = length;
            maxNum = curr;
        }
        else {
            maxLength = MAX(length, maxLength);
        }     
    }

    return maxLength;
}