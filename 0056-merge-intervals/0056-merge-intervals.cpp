class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // sort the intervals by their start time
        sort(intervals.begin(), intervals.end(),
            [](vector<int> &lhs. vector<int> &rhs) { return lhs.front() < rhs.front(); } );

        // push the first interval
        auto it = intervals.begin();
        ans.emplace_back(*it); 

        for (; it != intervals.end(); ++it) {
            auto &last = ans.back();

            // verify if the next interval is completely within the current
            if (last.back() >= it->back()) {
                continue;
            }

            if (last.back() >= it->front()) {
                last.back() = it->back();
            }
            else {
                ans.emplace_back(*it);
            }
        }

        return ans;
    }
};