class Solution {
    struct Edge {
        int dest;
        double prob;

        /* CONSTRUCTOR */
        Edge(int dest, double prob) : dest(dest), prob(prob) {}
    };

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // initialize the graph
        vector<vector<Edge>> graph(n);

        for (int i = 0; i < edges.size(); ++i) {
            const auto &edge = edges[i];
            int src = edge[0], dest = edge[1];

            graph[src].emplace_back(Edge(dest, succProb[i]));
            graph[dest].emplace_back(Edge(src, succProb[i]));
        }

        // initialize the list of visited nodes
        unordered_set<int> visited;

        // initialize the priority queue
        auto comparator = [](const pair<int, double> &lhs, const pair<int, double> &rhs) { return lhs.second < rhs.second; };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(comparator)> pq(comparator);

        pq.emplace(start_node, 1);

        // execute Dijkstra's shortest path algorithm
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            // verify if we have reached the destination
            if (curr.first == end_node) {
                return curr.second;
            }

            visited.insert(curr.first);

            // visit the adjacent nodes
            for (Edge &e : graph[curr.first]) {
                int node = e.dest;
                double prob = e.prob;

                if (prob >= 0 && visited.find(node) == visited.end()) {
                    pq.emplace(node, curr.second * prob);
                }
            }
        }

        return 0; // no path was found, return 0
    }
};
