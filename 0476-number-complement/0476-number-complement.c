int findComplement(int num) {
    int complement = 0, shift = 0;

    while (num) {
        complement |= !(num & 1) << shift++;
        num >>= 1;
    }

    return complement;
}