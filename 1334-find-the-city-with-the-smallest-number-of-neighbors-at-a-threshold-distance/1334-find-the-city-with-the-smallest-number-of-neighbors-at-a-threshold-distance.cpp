class Solution {
    int dijkstra(int node, int n, vector<int> &matrix, int distanceThreshold) {
        vector<bool> visitedCities(n, false);

        std::set<std::pair<int, int>> queue;
        queue.insert({0, node});

        while (!queue.empty()) {
            // find the nearest city
            auto top = queue.begin();

            // verify if the threshold has been exceeded
            int curr = top->second;
            int distance = top->first;

            if (distance > distanceThreshold) {
                break;
            }

            // set the current city as visited
            visitedCities[curr] = true;
            queue.erase(top);
            
            // push the adjacent nodes to the queue
            for (int adj = 0; adj < n; adj++) {
                int weight = matrix[curr * n + adj];

                if (!visitedCities[adj] && weight > 0) {
                    queue.insert({distance + weight, adj});
                }
            }
        }

        // count the number of visited cities
        int visited = -1;

        for (bool b : visitedCities) {
            visited += b;
        }

        return visited;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create the distance matrix
        vector<int> matrix(n * n, -1);

        for (auto &edge : edges) {
            int from = edge[0];
            int to = edge[1];

            matrix[from * n + to] = matrix[to * n + from] = edge[2];
        }

        // compute the city with the smallest number of neighbors
        int city = 0;
        int minCities = INT_MAX;

        for (int node = 0; node < n; node++) {
            int visitedCities = dijkstra(node, n, matrix, distanceThreshold);

            if (visitedCities <= minCities) {
                city = node;
                minCities = visitedCities;
            }
        }

        return city;
    }
};