int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
    int n = *matColSize;

    // create arrays for storing the coordinates of the integers
    int *rowCoords = (int *) malloc(arrSize * sizeof(int)),
        *colCoords = (int *) malloc(arrSize * sizeof(int));

    // O(m * n)
    for (int i = 0; i < matSize; ++i) {
        int *row = mat[i];

        for (int j = 0; j < n; ++j) {
            int num = row[j] - 1;

            rowCoords[num] = i;
            colCoords[num] = j;
        }
    }

    // create arrays for storing the number of painted cells
    // in each column and row
    int *paintedRows = (int *) calloc(matSize, sizeof(int)),
        *paintedCols = (int *) calloc(n, sizeof(int));

    // iterate through the array and paint the matrix
    int index;

    for (index = 0; index < arrSize; ++index) {
        int num = arr[index] - 1;

        // fetch the coordinates
        int row = rowCoords[num], col = colCoords[num];

        // determine if a row or column has been fully painted
        if (++paintedRows[row] == n || ++paintedCols[col] == matSize) {
            break;
        }
    }

    return index;
}