bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int n = *matrixColSize - 1;

    // search the row
    int *row;
    int lower = 0, upper = matrixSize - 1;

    // O(log m)
    while (lower <= upper) {
        int middle = (lower + upper) / 2;
        row = matrix[middle];

        // verify if the first element of the row is greater than the target
        if (row[0] > target) {
            upper = middle - 1;
        }
        // verify if the last element of the row is lower than the target
        else if (row[n] < target) {
            lower = middle + 1;
        }
        else {
            break;
        }
    }

    // O(log n)
    lower = 0; upper = n;

    while (lower <= upper) {
        int middle = (lower + upper) / 2;

        if (row[middle] == target) {
            return true;
        }
        else if (row[middle] < target) {
            lower = middle + 1;
        }
        else {
            upper = middle - 1;
        }
    }

    return false;
}