bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false;
    }

    for (; (n & 0b11) == 0; n /= 4);
    return n == 1;
}