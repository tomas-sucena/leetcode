int maxSum(int* nums, int numsSize) {
    int sum = 0, max = *nums;
    bool isInArray[100];
    
    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];

        // determine if the element should be added to the sum
        if (num > 0 && !isInArray[num - 1]) {
            sum += num;
            isInArray[num - 1] = true;
        }

        // determine if the element is the maximum
        if (num > max) {
            max = num;
        }
    }

    return (max < 0) ? max : sum;
}