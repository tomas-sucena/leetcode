unsigned char countBits(int n) {
    unsigned char bits = 32;
    unsigned mask = (unsigned) 1 << 31;

    for (; !(n & mask); mask >>= 1) {
        --bits;
    }
    
    return bits;
}

int concatenatedBinary(int n){
    int ans = 1;

    for (int i = 2; i <= n; ++i) {
        unsigned char shift = countBits(i);

        // concatenate the next number
        ans = (i | ((long) ans << shift)) % 1000000007;
    }

    return ans;
}