/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **triangle = (int **) malloc(numRows * sizeof(int*));

    *returnSize = numRows;
    int *colSizes = *returnColumnSizes = (int *) malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; ++i) {
        int *row = triangle[i] = (int *) malloc((i + 1) * sizeof(int));
        colSizes[i] = i + 1;

        // fill the row
        row[0] = row[i] = 1;

        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}