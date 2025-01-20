int minimumOperations(int** grid, int gridSize, int* gridColSize) {
    int ans = 0;

    for (int j = 0; j < *gridColSize; ++j) {
        int prev = grid[0][j];

        for (int i = 1; i < gridSize; ++i) {
            int curr = grid[i][j];
            int diff = prev - curr;

            if (diff++ >= 0) {
                ans += diff;
                curr += diff;
            }

            prev = curr;
        }
    }

    return ans;
}