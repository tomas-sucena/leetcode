int countServers(int** grid, int gridSize, int* gridColSize) {
    int ans = 0, n = *gridColSize;
    int *colServers = (int *) calloc(n, sizeof(int));

    // visit the rows
    // O(m * n)
    for (int i = 0; i < gridSize; ++i) {
        int servers = 0;

        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                ++servers;
                ++colServers[j];
            }
        }

        // verify if the row has at least two servers
        if (servers > 1) {
            ans += servers; // update the answer
            memset(grid[i], 0, n * sizeof(int));
        }
    }

    // visit the columns
    // O(m * n)
    for (int j = 0; j < n; ++j) {
        // skip unfeasible columns
        if (colServers[j] <= 1) {
            continue;
        }

        for (int i = 0; i < gridSize; ++i) {
            ans += grid[i][j];
        }
    }

    return ans;
}
