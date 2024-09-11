int minBitFlips(int start, int goal) {
    // XOR the numbers
    start ^= goal;
    int mask = 1;

    // count the 1 bits
    int ans = 0;

    for (int bit = 0; bit < 31; ++bit) {
        ans += !!(start & 1 << bit);
    }

    return ans;
}