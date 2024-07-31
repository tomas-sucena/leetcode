#define MAX(a, b) ((a > b) ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int max = *nums, sum = max;

    for (int i = 1; i < numsSize; ++i) {
        // determine if the current number and sum are negative
        switch ((sum < 0) << 1 | (nums[i] < 0)) {
            // positive sum, positive number
            case 0:
                sum += nums[i];
                max = MAX(sum, max);

                break;

            // positive sum, negative number
            case 1:
                max = MAX(sum, max);
                sum += nums[i];

                break;

            // negative sum, positive number
            case 2:
                sum = nums[i];
                max = MAX(nums[i], max);

                break;

            // negative sum, negative number
            case 3:
                sum = MAX(nums[i], sum);
                max = MAX(sum, max);

                break;
        }        
    }

    return max;
}