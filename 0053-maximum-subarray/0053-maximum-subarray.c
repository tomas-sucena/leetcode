#define MAX(a, b) ((a > b) ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int max = *nums, sum = max;

    for (int i = 1; i < numsSize; ++i) {
        switch ((sum >= 0) << 1 | (nums[i] >= 0)) {
            // negative sum, negative number
            case 0:
                sum = MAX(nums[i], sum);
                max = MAX(sum, max);

                break;

            // negative sum, positive number
            case 1:
                sum = nums[i];
                max = MAX(nums[i], max);

                break;

            // positive sum, negative number
            case 2:
                max = MAX(sum, max);
                sum += nums[i];

                break;
            

            // positive sum, positive number
            case 3:
                sum += nums[i];
                max = MAX(sum, max);

                break;
        }

        
    }

    return max;
}