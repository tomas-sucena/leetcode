// Depth-First Search
void dfs(char **grid, int row, int col, int rows, int cols) {
    if (grid[row][col] != '1') {
        return;
    }

    // set the current cell as visited
    grid[row][col] = 0;

    // visit the adjacent cells
    // left
    if (col - 1 >= 0) {
        dfs(grid, row, col - 1, rows, cols);
    }

    // right
    if (col + 1 < cols) {
        dfs(grid, row, col + 1, rows, cols);
    }

    // up
    if (row - 1 >= 0) {
        dfs(grid, row - 1, col, rows, cols);
    }

    // down
    if (row + 1 < rows) {
        dfs(grid, row + 1, col, rows, cols);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands = 0, n = *gridColSize;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < n; ++j) {
            // skip non-islands
            if (grid[i][j] != '1') {
                continue;
            }

            // visit all cells that belong
            // to the current island
            dfs(grid, i, j, gridSize, n);
            ++islands;
        }
    }

    return islands;
}