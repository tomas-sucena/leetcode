/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // initialize the new integer
    int *integer = malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize;

    // increment the input integer to obtain the new integer
    _Bool carry = 1;

    for (int i = digitsSize; i; --i) {
        int digit = digits[i - 1] + carry;

        // update the new integer
        integer[i] = digit % 10;
        
        // update the carry
        carry = (digit == 10);
    }

    // if there is carry, append it to the
    // beginning of the new integer
    if (carry) {
        integer[0] = 1;
        ++(*returnSize);
    }
    else {
        ++integer;
    }

    return integer;
}