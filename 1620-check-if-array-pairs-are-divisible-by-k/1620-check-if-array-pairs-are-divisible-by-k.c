int lessThan(const void *a, const void *b) {
    return (*(int*) a) - (*(int*) b);
}

// taken from
// https://stackoverflow.com/questions/1907565/c-and-python-different-behaviour-of-the-modulo-operation
int mod(int n, int k) {
    return ((n % k) + k) % k;
}

// O(n * log(n))
bool canArrange(int* arr, int arrSize, int k) {
    // transform the array so that each number
    // is replaced by its value % k
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = mod(arr[i], k);
    }

    // sort the array
    qsort(arr, arrSize, sizeof(int), lessThan);

    // count the number of 0s
    int left = 0;
    
    for (; left < arrSize && arr[left] == 0; ++left);

    // ensure the number of 0s is even
    if (left % 2) {
        return false;
    }

    // ensure that, for all numbers, there exists another
    // number such that their sum equals k
    int right = arrSize;

    while (left < right) {
        if (arr[left++] + arr[--right] != k) {
            return false;
        }
    }

    return true;
}
