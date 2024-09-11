int minBitFlips(int start, int goal) {
    // XOR the numbers
    start ^= goal;

    // count the 1 bits
    int ans = 0;

    for (; start; start >>= 1) {
        ans += !!(start & 1);
    }

    return ans;
}