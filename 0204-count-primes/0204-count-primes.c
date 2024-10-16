int countPrimes(int n) {
    // base case
    if (n < 3) {
        return 0;
    }

    int prime = n / 2; // NOTE: All even numbers are NOT prime, so exclude them.
    bool *notPrime = calloc(n, sizeof(bool));

    for (int i = 3; i < sqrt(n); i += 2) {
        // skip numbers already known to not be prime
        if (notPrime[i]) {
            continue;
        }

        int step = i * 2;

        for (int j = i + step; j < n; j += step) {
            // skip numbers already known to not be prime
            if (notPrime[j]) {
                continue;
            }

            --prime;
            notPrime[j] = true;
        }
    }

    return prime;
}