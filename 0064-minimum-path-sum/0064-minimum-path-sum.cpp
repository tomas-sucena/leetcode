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

        // set all cells as unvisited
        vector<vector<bool>> unvisited(m, vector<bool>(n, true));

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
            if (curr.row && unvisited[curr.row - 1][curr.col]) {
                int row = curr.row - 1, col = curr.col;

                pq.push(Point(row, col, curr.value + grid[row][col]));
                unvisited[row][col] = false; // set the current cell as visited
            }

            if (curr.col && unvisited[curr.row][curr.col - 1]) {
                int row = curr.row, col = curr.col - 1;
            
                pq.push(Point(row, col, curr.value + grid[row][col]));
                unvisited[row][col] = false; // set the current cell as visited
            }
        }

        // in theory, this return statement should never be reached
        return -1;
    }
};