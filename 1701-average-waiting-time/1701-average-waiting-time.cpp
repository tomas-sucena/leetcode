class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;
        int time = -1;

        for (auto &customer : customers) {
            time = std::max(time, customer[0]) + customer[1];
            sum += time - customer[0];
        }

        return sum / customers.size();
    }
};