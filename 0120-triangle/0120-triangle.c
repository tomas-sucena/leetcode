int min(int a, int b) {
    return (a < b)
        ? a
        : b;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // initialize an auxiliary array for memoization
    int **sums = malloc(triangleSize * sizeof(int*));

    // initialize and fill the first row
    *sums = malloc(sizeof(int));
    **sums = **triangle;

    // fill the remaining rows of the memoization array
    for (int i = 1; i < triangleSize; ++i) {
        // initialize the row
        sums[i] = malloc((i + 1) * sizeof(int));
        
        // fill the row
        int prev = sums[i - 1][0];
        sums[i][0] = triangle[i][0] + prev;

        for (int j = 1; j < i; ++j) {
            int curr = sums[i - 1][j];
            sums[i][j] = triangle[i][j] + min(prev, curr);
            
            prev = curr;
        }

        sums[i][i] = triangle[i][i] + prev;
    }

    // find the minimum path by iterating through the last row
    // of the memoization array
    int minSum = INT_MAX;

    for (int i = 0; i < triangleSize; ++i) {
        minSum = min(minSum, sums[triangleSize - 1][i]);
    }

    return minSum;    
}