int countSubarrays(int n) {
    n -= 2;
    return (n + 1) * (n / 2) + (n / 2 + 1) * (n & 1);
}

int numberOfArithmeticSlices(int* nums, int numsSize) {
    if (numsSize < 3) {
        return 0;
    }
    
    // compute the differences
    int ans = 0, streak = 2;
    int diff = nums[1] - nums[0];

    for (int i = 1; i < numsSize - 1; ++i) {
        int currDiff = nums[i + 1] - nums[i];
        
        if (diff == currDiff) {
            ++streak;
            continue;
        }

        ans += countSubarrays(streak);
        diff = currDiff; streak = 2;
    }

    return ans + countSubarrays(streak);
}