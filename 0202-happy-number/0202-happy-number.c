bool isHappy(int n) {
    while (n > 9) {
        // compute the next number
        int next = 0;

        for (; n; n /= 10) {
            unsigned char digit = n % 10;
            next += digit * digit;
        }

        n = next;
    }

    // NOTE: 7 is the only other single-digit happy number.
    return n == 1 || n == 7;
}