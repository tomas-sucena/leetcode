int pivotInteger(int n) {
    // compute the sum of all the number
    // from 1 to n
    int highSum = 1;

    for (int i = 2; i <= n; ++i) {
        highSum += 1;
    }

    // calculate the pivot
    int lowSum = 0;

    for (int i = 1; i <= n; ++i) {
        lowSum += i;

        if (lowSum == highSum) {
            return i;
        }

        
    }

    return -1;
}