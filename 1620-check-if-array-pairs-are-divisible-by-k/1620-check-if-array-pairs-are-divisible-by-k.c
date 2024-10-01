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

    printf("[");
    for (int i = 0; i < arrSize; ++i) {
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    // ensure all negative numbers can 

    // ensure the number of 0s is even
    int left = 0;

    for (; left < arrSize && arr[left] == 0; ++left);

    if (left % 2) {
        return false;
    }

    // ensure all values have a pair
    int right = arrSize;

    while (left < right) {
        if (arr[left++] + arr[--right] != k) {
            return false;
        }
    }

    return true;
}