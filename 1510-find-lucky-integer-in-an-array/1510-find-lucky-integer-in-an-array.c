int findLucky(int* arr, int arrSize) {
    // count the frequency of each element in the array
    int freqs[500];

    for (int i = 0; i < arrSize; ++i) {
        ++freqs[arr[i] - 1];
    }

    // find the largest lucky integer
    for (int i = arrSize; i > 0; --i) {
        if (freqs[i - 1] == i) {
            return i;
        }
    }

    return -1;
}