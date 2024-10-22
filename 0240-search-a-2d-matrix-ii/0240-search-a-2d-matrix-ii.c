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

// search a column for the target
bool colBinarySearch(int **matrix, int col, int colSize, int target) {
    int lower = 0, upper = colSize - 1;

    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        int num = matrix[mid][col];

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

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int n = *matrixColSize;

    // determine which is faster - search the rows or the columns
    if (matrixSize <= n) {
        // search each row for the target
        // O(m * log(n))
        for (int i = 0; i < matrixSize && matrix[i][0] <= target; ++i) {
            if (rowBinarySearch(matrix[i], n, target)) {
                return true;
            }
        }
    }
    else {
        // search each column for the target
        // O(n * log(m))
        for (int i = 0; i < n && matrix[0][i] <= target; ++i) {
            if (colBinarySearch(matrix, i, matrixSize, target)) {
                return true;
            }
        }
    }

    return false;
}