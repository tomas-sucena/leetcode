// travel right - from the lowest to the highest column
void right(int **matrix, int num, int minRow, int minCol, int maxRow, int maxCol) {
    if (minCol == maxCol) {
        return;
    }

    for (int col = minCol; col < maxCol; ++col) {
        matrix[minRow][col] = ++num;
    }

    down(matrix, num, minRow + 1, minCol, maxRow, maxCol);
}

// travel down - from the lowest to the highest row
void down(int **matrix, int num, int minRow, int minCol, int maxRow, int maxCol) {
    if (minRow == maxRow) {
        return;
    }
    
    for (int row = minRow; row < maxRow; ++row) {
        matrix[row][maxCol - 1] = ++num;
    }

    left(matrix, num, minRow, minCol, maxRow, maxCol - 1);
}

// travel left - from the highest to the lowest column
void left(int **matrix, int num, int minRow, int minCol, int maxRow, int maxCol) {
    if (minCol == maxCol) {
        return;
    }

    for (int col = maxCol - 1; col >= minCol; --col) {
        matrix[maxRow - 1][col] = ++num;
    }

    up(matrix, num, minRow, minCol, maxRow - 1, maxCol);
}

// travel upwards - from the highest to the lowest row
void up(int **matrix, int num, int minRow, int minCol, int maxRow, int maxCol) {
    if (minRow == maxRow) {
        return;
    }

    for (int row = maxRow - 1; row >= minRow; --row) {
        matrix[row][minCol] = ++num;
    }

    right(matrix, num, minRow, minCol + 1, maxRow, maxCol);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // initialize the matrix
    int **matrix = malloc(n * sizeof(int*));

    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        matrix[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // recursively fill the matrix
    right(matrix, 0, 0, 0, n, n);
    return matrix;
}