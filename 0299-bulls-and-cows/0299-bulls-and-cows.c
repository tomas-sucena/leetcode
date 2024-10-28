// for determining the number of digits of a number
int countDigits(int num) {
    int digits = 0;

    for (; num; num /= 10) {
        ++digits;
    }

    return (digits > 0)
        ? digits
        : 1; // NOTE: The number 0 requires 1 digit to be written.
}

// O(n)
char* getHint(char* secret, char* guess) {
    // count the number of bulls
    int occurrences[10], bulls = 0, size = 0;

    for (; *secret; ++secret, ++guess, ++size) {
        char secretDigit = *secret;

        // bull
        if (secretDigit == *guess) {
            ++bulls;
            *guess = -1; // set the current digit as a bull
        }
        else {
            ++occurrences[secretDigit - '0']; 
        }
    }

    guess -= size; // rewind the guess

    // count the number of cows
    int cows = 0;

    for (; *guess; ++guess) {
        char guessedDigit = *guess;

        // skip bull digits
        if (guessedDigit < 0) {
            continue;
        }

        int index = guessedDigit - '0';

        // cow
        if (occurrences[index] > 0) {
            ++cows;
            --occurrences[index];
        }
    }

    // create the hint
    char *hint = malloc(9 * sizeof(char));

    int digits = countDigits(bulls);
    char *temp = hint + digits;

    for (int i = -1; i >= -digits; --i) {
        temp[i] = (bulls % 10) + '0';
        bulls /= 10;
    }

    *temp++ = 'A';
    temp += (digits = countDigits(cows));

    for (int i = -1; i >= -digits; --i) {
        temp[i] = (cows % 10) + '0';
        cows /= 10;
    }
    
    *temp++ = 'B';
    *temp = '\0';

    return hint;
}