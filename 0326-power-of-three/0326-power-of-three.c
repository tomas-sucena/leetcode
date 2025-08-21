bool isPowerOfThree(int n) {
    for (; n > 1 && n % 3 == 0; n /= 3);
    return n == 1;
}