int mySqrt(int x) {
    int left = 0, right = 1 + x / 2;

    while (left < right) {
        int middle = 1 + (left + right) / 2;
        int sqrt = x / middle;

        if (sqrt < middle) {
            right = middle - 1;
        }
        else {
            left = middle;
        }
    }

    return right;
}