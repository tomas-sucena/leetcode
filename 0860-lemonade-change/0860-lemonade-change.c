bool lemonadeChange(int* bills, int billsSize) {
    int cash[5];

    for (int i = 0; i < billsSize; ++i) {
        // add the bill to our money
        int bill = bills[i] / 5;
        ++cash[bill];

        // compute the change
        int change = bill - 1;

        // ensure we have enough cash for the change
        for (int j = 2; change && j > 0; --j) {
            while (change >= j && cash[j]) {
                --cash[j];
                change -= j;
            }
        }

        if (change) {
            return false;
        }
    }

    return true;
}