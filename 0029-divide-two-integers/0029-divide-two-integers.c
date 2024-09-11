int divide(int dividend, int divisor) {
    long D = dividend, d = divisor;
    
    // determine the signal of the result
    bool negative = false;

    if (D < 0) {
        D *= -1;
        negative = true;
    }

    if (d < 0) {
        d *= -1;
        negative ^= true;
    }

    // compute the result by subtracting the dividend by the divisor
    long ans = 0;

    if (d == 1) {
        ans = D;
    }
    else {
        for (; D >= d; D -= d) ++ans;
    }
    
    // handle overflows
    if (negative) {
        return (-ans < INT_MIN)
            ? INT_MIN
            : -ans;
    }

    return (ans > INT_MAX) 
        ? INT_MAX
        : ans;
}