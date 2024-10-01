// travel right - from the lowest to the highest column
void right(int **matrix, int *nums, int minRow, int minCol, int maxRow, int maxCol) {
    if (minCol == maxCol) {
        return;
    }

    for (int col = minCol; col < maxCol; ++col) {
        *nums++ = matrix[minRow][col];
    }

    down(matrix, nums, minRow + 1, minCol, maxRow, maxCol);
}

// travel down - from the lowest to the highest row
void down(int **matrix, int *nums, int minRow, int minCol, int maxRow, int maxCol) {
    if (minRow == maxRow) {
        return;
    }
    
    for (int row = minRow; row < maxRow; ++row) {
        *nums++ = matrix[row][maxCol - 1];
    }

    left(matrix, nums, minRow, minCol, maxRow, maxCol - 1);
}

// travel left - from the highest to the lowest column
void left(int **matrix, int *nums, int minRow, int minCol, int maxRow, int maxCol) {
    if (minCol == maxCol) {
        return;
    }

    for (int col = maxCol - 1; col >= minCol; --col) {
        *nums++ = matrix[maxRow - 1][col];
    }

    up(matrix, nums, minRow, minCol, maxRow - 1, maxCol);
}

// travel upwards - from the highest to the lowest row
void up(int **matrix, int *nums, int minRow, int minCol, int maxRow, int maxCol) {
    if (minRow == maxRow) {
        return;
    }

    for (int row = maxRow - 1; row >= minRow; --row) {
        *nums++ = matrix[row][minCol];
    }

    right(matrix, nums, minRow, minCol + 1, maxRow, maxCol);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;

    // initialize the array
    int *nums = malloc(*returnSize * sizeof(int*));

    // recursively fill the array
    right(matrix, nums, 0, 0, matrixSize, *matrixColSize);
    return nums;
}