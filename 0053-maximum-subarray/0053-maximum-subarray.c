#define MAX(a, b) ((a > b) ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int max = *nums, sum = max;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] < -sum) {
            max = MAX(nums[i], max);
            sum = 0;

            continue;
        }

        sum += nums[i];
        max = MAX(sum, max);
    }

    return max;
}