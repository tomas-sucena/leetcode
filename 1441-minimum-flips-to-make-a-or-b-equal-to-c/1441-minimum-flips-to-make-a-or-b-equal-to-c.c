int minFlips(int a, int b, int c){
    int ans = 0;

    while (a || b || c) {
        bool bitA = a & 1, bitB = b & 1, bitC = c & 1;
        a >>= 1; b >>= 1; c >>= 1;

        // verify if any bit flips are needed
        if ((bitA | bitB) == bitC) {
            continue;
        }

        ans += (bitC)
            ? 1             // if bitC is 1, only one bit flip is required
            : bitA + bitB;  // if bitC is 0, at most two bit flips are needed, if both bitA and bitB are 1
    }

    return ans;
}