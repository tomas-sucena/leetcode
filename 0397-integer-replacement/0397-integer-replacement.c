int countTwos(long n) {
    int twos = 0;

    for (; n % 2 == 0; n /= 2) {
        ++twos;
    }

    return twos;
}

int integerReplacement(int n) {
    // base case
    if (n < 4) {
        return n - 1;
    }

    // if even, divide by two
    if (n % 2 == 0) {
        return 1 + integerReplacement(n / 2);
    }

    // if odd, determine if it is better
    // to add or subtract one
    int add = countTwos((long) n + 1), subtract = countTwos(n - 1);
    int choice;
    
    if (add > subtract) {
        choice = add;
        n = ((long) n + 1) >> add;
    }
    else {
        n = (n - 1) >> subtract;
        choice = subtract;
    }

    return 1 + choice + integerReplacement(n);
}