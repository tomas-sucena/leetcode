int minBitFlips(int start, int goal) {
    // XOR the numbers
    start ^= goal;

    // count the 1 bits
    int ans = 0;

    for (unsigned mask = (unsigned) 1 << 31; mask; mask >>= 1) {
        ans += !!(start & mask);
    }

    return ans;
}