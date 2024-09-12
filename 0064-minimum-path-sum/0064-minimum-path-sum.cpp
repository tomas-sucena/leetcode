class Solution {
    struct Point {
        uint8_t row, col;
        int value;

        Point(uint8_t row, uint8_t col, int value)
            : row(row), col(col), value(value) {}

        bool operator<(const Point &p) const {
            return value > p.value;
        }
    };

public:
    int minPathSum(vector<vector<int>>& grid) {
        uint8_t m = grid.size(), n = grid[0].size();

        // initialize the min-heap
        priority_queue<Point> pq;
        pq.push(Point(--m, --n, grid[m][n]));

        while (!pq.empty()) {
            Point curr = pq.top();
            pq.pop();

            // verify if we have reached the top left corner of the grid
            if (curr.row == 0 && curr.col == 0) {
                return curr.value;
            }

            // push the adjacent cells to the priority queue
            int row = curr.row - 1, col = curr.col;

            if (curr.row && grid[row][col] >= 0) {
                pq.push(Point(row, col, curr.value + grid[row][col]));
                grid[row][col] = -1; // set the current cell as visited
            }

            row = curr.row, col = curr.col - 1;

            if (curr.col && grid[row][col] >= 0) {            
                pq.push(Point(row, col, curr.value + grid[row][col]));
                grid[row][col] = -1; // set the current cell as visited
            }
        }

        // in theory, this return statement should never be reached
        return INT_MAX;
    }
};