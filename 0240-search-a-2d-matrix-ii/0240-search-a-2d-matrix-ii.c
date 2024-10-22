// search a row for the target
bool rowBinarySearch(int *row, int rowSize, int target) {
    int lower = 0, upper = rowSize - 1;

    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        int num = row[mid];

        if (num == target) {
            return true;
        }
        else if (num < target) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }

    return false;
}

// O(m * log(n))
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int n = *matrixColSize;

    // search each row for the target
    for (int i = 0; i < matrixSize && matrix[i][0] <= target; ++i) {
        if (rowBinarySearch(matrix[i], n, target)) {
            return true;
        }
    }

    return false;
}