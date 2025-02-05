int max(int a, int b) {
    return (a > b)
        ? a
        : b;
}

int maxAdjacentDistance(int* nums, int numsSize) {
    int ans = abs(*nums - nums[--numsSize]);

    for (int i = 0; i < numsSize; ++i) {
        ans = max(ans, abs(nums[i] - nums[i + 1]));
    }

    return ans;
}