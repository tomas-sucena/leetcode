class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort the costs such that the people with a cheap flights
        // to city A but expensive flights to city B come first
        sort(costs.begin(), costs.end(),
            [](vector<int> &lhs, vector<int> &rhs) {
                return lhs.front() - lhs.back() < rhs.front() - rhs.back();
        });

        int n = costs.size() / 2;
        auto it = costs.begin();

        // compute the cost of flying n people to city A
        int minCost = 0;
        
        while (n--) {
            minCost += it++->front();
        }

        // compute the cost of flying the remaining people to city B
        while (it != costs.end()) {
            minCost += it++->back();
        }

        return minCost;
    }
};