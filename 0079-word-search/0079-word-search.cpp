class Solution {
    // struct that represents a step of the BFS algorithm
    struct Position {
        int i, j;
        const char *ptr;
        unordered_set<int> visited;

        /* CONSTRUCTOR */
        Position(int i, int j, const std::string &word)
            : i(i), j(j), ptr(word.c_str() + 1) {}

        /* METHODS */
        void setVisited() {
            visited.insert((i << 6) + j);
        }

        bool canBeVisited() const {
            return visited.find((i << 6) + j) == visited.end();
        }
    };

    bool find(const Position& initial, vector<vector<char>>& board, int n) {
        // initialize the queue
        queue<Position> q;
        q.emplace(initial);

        // BFS
        while (!q.empty()) {
            Position curr = q.front();
            q.pop();

            // verify if a match was found
            if (*curr.ptr == '\0') {
                return true;
            }

            // set the current position as visited
            curr.setVisited();

            vector<Position> neighbors(4, curr);
            --neighbors[0].i; // up
            ++neighbors[1].i; // down
            --neighbors[2].j; // left
            ++neighbors[3].j; // right

            for (Position &p : neighbors) {
                // verify if the position is valid
                if (p.i >= 0 && p.i < board.size()
                    && p.j >= 0 && p.j < n
                    && p.canBeVisited()
                    && board[p.i][p.j] == *p.ptr++) {
                        q.emplace(p);
                }
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.front().size();

        // count the frequency of each character
        unordered_map<char, int> chars;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                ++chars[board[i][j]];
            }
        }

        // determine if it is more advantageous to begin searching
        // for the last character
        if (chars[word.back()] < chars[word.front()]) {
            reverse(word.begin(), word.end());
        }

        // search for a match
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word.front() && find(Position(i, j, word), board, n)) {
                    return true;
                }
            }
        }

        return false;
    }
};