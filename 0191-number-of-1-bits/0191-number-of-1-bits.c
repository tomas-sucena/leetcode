int hammingWeight(int n) {
    int ans = 0;

    for (; n; n >>= 1) {
        ans += n & 1;
    }

    return ans;
}