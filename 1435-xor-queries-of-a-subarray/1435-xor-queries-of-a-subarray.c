/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *xors = malloc(arrSize * sizeof(int));

    // fill the table
    int xor = 0;

    for (int i = 0; i < arrSize; ++i) {
        xor = xors[i] = xor ^ arr[i];
    }

    // solve the queries
    int *results = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; ++i) {
        int left = queries[i][0], right = queries[i][1];

        results[i] = left 
            ? xors[right] ^ xors[left - 1]
            : xors[right];
    }

    return results;
}